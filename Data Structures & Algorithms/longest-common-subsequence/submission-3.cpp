class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp;

        dp.assign(2, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++)
        {
            int currrow = i % 2;
            int prevrow = ((i - 1) + 2) % 2;

            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[currrow][j] = 0;
                }
                else if (text1[i - 1] == text2[j - 1])
                {
                    dp[currrow][j] = 1 + dp[prevrow][j - 1];
                }
                else
                {
                    dp[currrow][j] = max(dp[prevrow][j], dp[currrow][j - 1]);
                }
            }
        }

        return dp[n % 2][m];
    }
};
