class Solution {
public:
    int f(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(i==n-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int d = triangle[i][j] +f(triangle,i+1,j,n,dp);
        int dg = triangle[i][j] +f(triangle,i+1,j+1,n,dp);
        return dp[i][j] = min(d,dg);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return f(triangle,0,0,n,dp);
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int i = n - 1;
        for (int j = i; j >= 0; j--)
        {
            dp[i][j] = triangle[i][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};