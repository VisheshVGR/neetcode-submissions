class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size(); // i

        vector<vector<int>> dp;

        // We can reduce dp state furtur to amount X 2
        // as we are only using previous state

        // amt, i
        dp.assign(amount + 1, vector<int>(2, -1));

        // if (amt == 0) return 0;
        for (int i = 0; i < 2; i++)
            dp[0][i] = 0;

        // if (i == 0) return INT_MAX / 2;
        for (int amt = 1; amt <= amount; amt++)
            dp[amt][0] = INT_MAX / 2;

        for (int i = 1; i <= n; i++)
        {
            for (int amt = 1; amt <= amount; amt++)
            {
                int currstate = i % 2;
                int prevstate = (i - 1) % 2;

                if (coins[i - 1] > amt)
                {
                    // not take
                    dp[amt][currstate] = dp[amt][prevstate];
                }
                else
                {
                    // take / not take
                    dp[amt][currstate] = min(
                        1 + dp[amt - coins[i - 1]][currstate],
                        dp[amt][prevstate]);
                }
            }
        }

        return (dp[amount][n] == INT_MAX / 2) ? -1 : dp[amount][n % 2];
    }
};