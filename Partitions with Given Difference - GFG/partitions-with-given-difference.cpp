//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod =1e9+7;
    int solve(int index,int target,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(index==0)
         {
             if(arr[0]==0 && target==0){return 2;}
              if (target==arr[0]||target==0){return 1;}
             return 0;
         }
         if(dp[index][target]!=-1){return dp[index][target];}
         int npick = solve(index-1,target,arr,dp);
         int pick =0;
         if(arr[index]<=target){pick = solve(index-1,target-arr[index],arr,dp);}
         return dp[index][target]= (pick +npick)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum =0;
      sum=accumulate(arr.begin(),arr.end(),sum);
        if((sum-d)<0 || (sum-d)%2!=0){return 0;}
        int target= (sum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends