class Solution
{
    vector<int> dp;

    int n;

public:
    int rob(vector<int> &nums)
    {
        n = nums.size();

        dp.assign(n + 1, -1);

        return max(dphelper(nums, n), dphelper(nums, n - 1));
    }

private:
    int dphelper(vector<int> &nums, int n)
    {
        if (n == 0)
            return 0;

        if (n == 1)
            return nums[n - 1];

        int &memo = dp[n];

        if (memo != -1)
            return memo;

        return memo = max(
                   nums[n - 1] + dphelper(nums, n - 2),
                   dphelper(nums, n - 1));
    }
};