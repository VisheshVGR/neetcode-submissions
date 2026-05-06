class Solution
{
    vector<vector<int>> dp;
    int n;

public:
    int rob(vector<int> &nums)
    {
        n = nums.size();

        // Special case
        if (n == 1)
            return nums[0];

        dp.assign(n + 1, vector<int>(2, -1));

        // Base cases
        dp[0][0] = dp[0][1] = 0;
        dp[1][1] = nums[0];
        dp[1][0] = 0;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j] = max(nums[i - 1] + dp[i - 2][j], dp[i - 1][j]);
            }
        }

        return max(dp[n][0], dp[n - 1][1]);
    }
};