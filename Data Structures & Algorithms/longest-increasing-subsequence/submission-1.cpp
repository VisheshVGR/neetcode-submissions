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

        dp.assign(n + 1, vector<int>(n + 2, -1));

        return LIShelper(nums, n, INVALID);
    }

private:
    // In recursion we check our curr idx should be strictly decreasing from lastIdx
    int LIShelper(const vector<int> &nums, int idx, int lastIdx)
    {
        // no elem in array
        if (idx == 0)
            return 0;

        int &memo = dp[idx][lastIdx];

        if (memo != -1)
            return memo;

        // If I'm first elem
        if (lastIdx == INVALID)
        {
            // pick / not pick
            return memo = max(
                       1 + LIShelper(nums, idx - 1, idx),
                       LIShelper(nums, idx - 1, lastIdx));
        }
        else
        {
            // I should be strictly decreasing from lastIdx

            // If I'm greater or equal to lastIdx
            // cant pick
            if (nums[idx - 1] >= nums[lastIdx - 1])
            {
                return memo = LIShelper(nums, idx - 1, lastIdx);
            }
            else
            {
                // pick / not pick
                return memo = max(
                           1 + LIShelper(nums, idx - 1, idx),
                           LIShelper(nums, idx - 1, lastIdx));
            }
        }
    }
};
