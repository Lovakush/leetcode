//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= matrix.size())return -1e8;
        if (i == 0)return matrix[i][j];
        if (dp[i][j] != -1)return dp[i][j];
        int u = matrix[i][j] + f(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
        return dp[i][j] = max(u, max(ld, rd));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int maxi = -1e9;
        for (int j = 0; j < N; j++)
            maxi = max(maxi, f(N - 1, j, Matrix, dp));
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends