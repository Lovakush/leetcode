class Solution {
public:
      int Tablulation(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp1(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    dp1[i][j] = grid[i][j];
                else
                {
                    int up, left;
                    up = left =grid[i][j];
                    if (i > 0)
                        up += dp1[i - 1][j];
                    else
                        up += 1e9;
                    if (j > 0)
                        left += dp1[i][j - 1];
                    else
                        left += 1e9;
                    dp1[i][j] = min(up,left);
                }
                
            }
        }
        return dp1[n - 1][m - 1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return  Tablulation(grid);
    }
};