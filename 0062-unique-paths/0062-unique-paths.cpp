class Solution {
public:
    int memoization(int m,int n, vector<vector<int>> &dp)
    {
        if(dp[m][n]!=-1)return dp[m][n];
        if(m==1 && n==1)return 1;
        if(m<1 || n<1)return 0;
        int up = memoization(m-1,n,dp);
        int left = memoization(m,n-1,dp);
        return dp[m][n] = up + left;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return memoization(m,n,dp);
    }
};