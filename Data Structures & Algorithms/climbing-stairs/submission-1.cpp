class Solution
{
    vector<int> dp;

public:
    int climbStairs(int n)
    {
        dp.assign(n + 1, -1);

        return dphelper(n);
    }

private:
    int dphelper(int n)
    {
        if (n < 0)
            return 0;

        if (n == 0)
            return 1;

        int &memo = dp[n];

        if (memo != -1)
            return memo;

        return memo = dphelper(n - 1) + dphelper(n - 2);
    }
};