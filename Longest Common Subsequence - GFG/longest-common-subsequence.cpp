//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    
    // memoization 
    int f(int i, int j, string t1, string t2,vector<vector<int>> &dp)
    {
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i]==t2[j]) return dp[i][j] =  1 + f(i-1,j-1,t1,t2,dp);
        return dp[i][j] = max(f(i,j-1,t1,t2,dp),f(i-1,j,t1,t2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // memoization 
        
        // int i = s1.size();
        // int j = s2.size();
        // vector<vector<int>> dp(i,vector<int>(j,-1));
        // return f(i,j,s1,s2,dp);
        
        // tabulation 
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        for(int i = 0 ;i<=x;i++)dp[i][0] = 0;
        for(int j=0;j<=y;j++)dp[0][j] = 0;
        for(int i=1;i<=x;i++)
        {
            for(int j = 1;j<=y;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j] =  1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[x][y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends