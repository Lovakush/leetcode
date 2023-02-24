//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   // 9 7 
	public:
	int mod =1e9+7;
	//{0,0,1}
	int solve(int ind, int sum, int arr[],vector<vector<int>> &dp)
	{
	    if(ind==0)
	    {
	        if(arr[0]==0&& sum==0){return 2;}
	        if(arr[0]==sum || sum==0){return 1;}
	        return 0;
	    }
	   if(dp[ind][sum]!=-1)return dp[ind][sum];
	    int notTake = solve(ind-1,sum,arr,dp);
	    int Take = 0;
	    if(arr[ind]<=sum)
	        Take = solve(ind-1,sum-arr[ind],arr,dp);
	   return dp[ind][sum] = (notTake + Take)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        // for(int ind=0;ind<n;ind++)
        //     dp[ind][0] = 1;
        // if(arr[0]<=sum)
        //     dp[0][arr[0]] = 1;
        // for(int ind=1;ind<n;ind++)
        // {
        //     for(int s=0;s<=sum;s++)
        //     {
        //         int notTake = dp[ind-1][s];
	       //     int Take = 0;
	       //     if(arr[ind]<=s)
	       //         Take = dp[ind-1][s-arr[ind]];
	       //     dp[ind][s] = notTake + Take;
        //     }
        // }
        return solve(n-1,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends