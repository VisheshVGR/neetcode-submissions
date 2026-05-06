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

        return max(dphelper(nums, n, false), dphelper(nums, n - 1, true));
    }

private:
    int dphelper(vector<int> &nums, int n, bool canrobfirsthouse)
    {
        // no house left to rob
        if (n == 0)
            return 0;

        if (n == 1)
        {
            // first house to rot
            if (canrobfirsthouse)
                return nums[n - 1];
            else
                return 0;
        }

        int &memo = dp[n][canrobfirsthouse];

        if (memo != -1)
            return memo;

        // rob this or dont rob
        return memo = max(
                   nums[n - 1] + dphelper(nums, n - 2, canrobfirsthouse),
                   dphelper(nums, n - 1, canrobfirsthouse));
    }
};