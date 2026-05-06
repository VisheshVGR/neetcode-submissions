class Solution
{
    vector<int> dp;

    int n;

public:
    int rob(vector<int> &nums)
    {
        n = nums.size();

        dp.assign(n + 1, -1);

        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(
                nums[i - 1] + dp[i - 2],
                dp[i - 1]);
        }

        return max(dp[n], dp[n - 1]);
    }
};