//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind,int w,int wt[],int val[],vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(wt[ind]<=w)return val[ind];
            return 0;
        }
        if(dp[ind][w]!=-1)return dp[ind][w];
        int notTake = 0 + solve(ind-1,w,wt,val,dp);
        int Take = INT_MIN;
        if(wt[ind]<=w)
        {
            Take = val[ind] + solve(ind-1,w-wt[ind],wt,val,dp);
        }
        return dp[ind][w] = max(notTake,Take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<vector<int>> dp(n,vector<int>(W+1,0));
      for(int w=wt[0];w<=W;w++)
        {
            dp[0][w] = val[0];
        }
      for(int ind=1;ind<n;ind++)
      {
          for(int w=0;w<=W;w++)
          {
                int notTake = 0 + dp[ind-1][w];
                int Take = INT_MIN;
                if(wt[ind]<=w)
                {
                    Take = val[ind] + dp[ind-1][w-wt[ind]];
                }
                dp[ind][w] = max(notTake,Take);
          }
      }
      return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends