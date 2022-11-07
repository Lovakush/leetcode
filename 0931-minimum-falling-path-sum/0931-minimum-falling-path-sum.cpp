// class Solution {
// public:
//     int f(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
//     {
//         if(j<0 || j>=matrix.size())return 1e8;
//         if(i==0)return matrix[i][j];
//         if(dp[i][j]!=-1)return dp[i][j];
//         int u = matrix[i][j] + f(i+1,j,matrix,dp);
//         int ld = matrix[i][j] +f(i+1,j-1,matrix,dp);
//         int rd = matrix[i][j] +f(i+1,j+1,matrix,dp);
//         return dp[i][j] = min(u, max(ld,rd));
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int>(n,0));
//         for(int j=0;j<n;j++)dp[0][j] = matrix[0][j];
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 int u = matrix[i][j] + f(i+1,j,matrix,dp);
//         int ld = matrix[i][j] +f(i+1,j-1,matrix,dp);
//         int rd = matrix[i][j] +f(i+1,j+1,matrix,dp);
//         return dp[i][j] = min(u, max(ld,rd));
//             }
//         }
//     }
// };


class Solution {
public:
    int f(int i, int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0 || j>=matrix.size())return 1e8;
        if(i==0)return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int u = matrix[i][j] + f(i-1,j,matrix,dp);
        int ld = matrix[i][j] +f(i-1,j-1,matrix,dp);
        int rd = matrix[i][j] +f(i-1,j+1,matrix,dp);
        return dp[i][j] = min(u, min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int mini = 1e9;
        for(int j=0;j<n;j++)
           mini = min(mini,f(n-1,j,matrix,dp));
        return mini;
    }
};