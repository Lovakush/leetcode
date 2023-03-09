//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    string str2 = "";
    int n = str.length();
    for(int i=n-1;i>=0;i--)
        str2+=str[i];
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> prev(n+1,0), curr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i-1]==str2[j-1]) curr[j] = 1 + prev[j-1];
            else
                curr[j] = max(curr[j-1],prev[j]);
        }
        prev = curr;
    }
    return n - prev[n];
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends