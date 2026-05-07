class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        vector<vector<int>> dp;

        dp.assign (10001, vector<int> (11, -1));

        int res = dphelper(dp, coins, n, amount);

        return (res == INT_MAX / 2) ? -1 : res;
    }

private:
    int dphelper(vector<vector<int>> &dp, vector<int> &coins, int i, int amount)
    {
        if (amount == 0)
            return 0;

        // no more ways left
        if (i == 0)
            return INT_MAX / 2;

        int &memo = dp[amount][i];

        if (memo != -1)
            return memo;

        // not take
        if (coins[i - 1] > amount)
            return memo = dphelper(dp, coins, i - 1, amount);

        // take / not take
        return memo = min(
            1 + dphelper(dp, coins, i, amount - coins[i - 1]),
            dphelper(dp, coins, i - 1, amount));
    }
};