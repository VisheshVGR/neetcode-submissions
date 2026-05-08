class Solution
{
public:
    int uniquePaths(int n, int m)
    {
        // go from top left to bottom right
        // by only taking right and bottom moves
        vector<vector<int>> dp(n, vector<int>(m, -1));

        dp[n - 1][m - 1] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                    continue;

                // if we are at right border -> can only go bottom
                if (j == m - 1)
                {
                    dp[i][j] = dp[i + 1][j];
                }
                // if we are at bottom border -> can only go right
                else if (i == n - 1)
                {
                    dp[i][j] = dp[i][j + 1];
                }
                else
                {
                    // we can go both right and bottom
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
