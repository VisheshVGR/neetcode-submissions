class Solution
{
    int n;
    int INVALID;

    vector<vector<int>> dp;

public:
    int lengthOfLIS(vector<int> &nums)
    {
        // Longest Strictly Increasing Subsequence

        n = nums.size();
        INVALID = n + 1;

        // idx, lastIdx
        dp.assign(n + 1, vector<int>(n + 2, -1));

        // Base case
        for (int i = 0; i <= n + 1; i++)
            dp[0][i] = 0;

        for (int idx = 1; idx <= n; idx++)
        {
            for (int lastIdx = 0; lastIdx <= n + 1; lastIdx++)
            {
                if (lastIdx == INVALID)
                {
                    dp[idx][lastIdx] = max(
                        1 + dp[idx - 1][idx],
                        dp[idx - 1][lastIdx]);
                }
                else
                {
                    if (nums[idx - 1] >= nums[lastIdx - 1])
                    {
                        dp[idx][lastIdx] = dp[idx - 1][lastIdx];
                    }
                    else
                    {
                        // pick / not pick
                        dp[idx][lastIdx] = max(
                            1 + dp[idx - 1][idx],
                            dp[idx - 1][lastIdx]);
                    }
                }
            }
        }

        return dp[n][INVALID];
    }
};