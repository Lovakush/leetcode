//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int target, int arr[],vector<vector<int>>&dp)
    {
        if(target==0)return 1;
        if(ind == 0)return arr[0] == target;
        if(dp[ind][target]!=-1)return dp[ind][target];
        int notTaken = solve(ind-1,target,arr,dp);
        bool taken = false;
        if(arr[ind]<=target)
            taken = solve(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]= notTaken||taken;
    }
    int equalPartition(int N, int arr[])
    {
        int sum =0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        int s = sum/2;
        vector<vector<int>> dp(N,vector<int>(s+1,-1));
        return solve(N-1,s,arr,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends