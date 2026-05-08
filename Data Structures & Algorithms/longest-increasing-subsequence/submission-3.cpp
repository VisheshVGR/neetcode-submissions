class Solution
{
    int n;
    int INVALID;

    vector<int> dp;

public:
    int lengthOfLIS(vector<int> &nums)
    {
        // Longest Strictly Increasing Subsequence

        n = nums.size();
        INVALID = n + 1;

        // As we only rely on last state
        // we can reduce DP furthur

        // idx, lastIdx
        dp.assign(n + 2, 0);

        for (int idx = 1; idx <= n; idx++)
        {
            for (int lastIdx = 0; lastIdx <= n + 1; lastIdx++)
            {
                if (lastIdx == INVALID)
                {
                    dp[lastIdx] = max(
                        1 + dp[idx],
                        dp[lastIdx]);
                }
                else
                {
                    if (nums[idx - 1] >= nums[lastIdx - 1])
                    {
                        dp[lastIdx] = dp[lastIdx];
                    }
                    else
                    {
                        // pick / not pick
                        dp[lastIdx] = max(
                            1 + dp[idx],
                            dp[lastIdx]);
                    }
                }
            }
        }

        return dp[INVALID];
    }
};