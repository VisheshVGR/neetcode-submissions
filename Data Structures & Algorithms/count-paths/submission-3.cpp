class Solution
{
public:
    int uniquePaths(int n, int m)
    {
        // go from top left to bottom right
        // by only taking right and bottom moves

        vector<int> dp(m, 0);

        dp[m - 1] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                    continue;

                // if we are at right border -> can only go bottom
                if (j == m - 1)
                {
                    dp[j] = dp[j];
                }
                // if we are at bottom border -> can only go right
                else if (i == n - 1)
                {
                    dp[j] = dp[j + 1];
                }
                else
                {
                    // we can go both right and bottom
                    dp[j] = dp[j] + dp[j + 1];
                }
            }
        }

        return dp[0];
    }
};