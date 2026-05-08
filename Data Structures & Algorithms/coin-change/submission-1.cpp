class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size(); // i

        vector<vector<int>> dp;

        // amt, i
        dp.assign(amount + 1, vector<int>(n + 1, -1));

        // if (amt == 0) return 0;
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;

        // if (i == 0) return INT_MAX / 2;
        for (int amt = 1; amt <= amount; amt++)
            dp[amt][0] = INT_MAX / 2;

        for (int i = 1; i <= n; i++)
        {
            for (int amt = 1; amt <= amount; amt++)
            {
                if (coins[i - 1] > amt)
                {
                    // not take
                    dp[amt][i] = dp[amt][i - 1];
                }
                else
                {
                    // take / not take
                    dp[amt][i] = min(
                        1 + dp[amt - coins[i - 1]][i],
                        dp[amt][i - 1]);
                }
            }
        }

        return (dp[amount][n] == INT_MAX / 2) ? -1 : dp[amount][n];
    }
};