class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, false);

        dp[n - 1] = true;

        for (int i = n - 2; i >= 0; i--)
        {
            bool canreach = false;

            for (int jump = nums[i]; jump >= 1; jump--)
            {
                if (dp[min(n - 1, i + jump)])
                {
                    canreach = true;
                    break;
                }
            }

            dp[i] = canreach;
        }

        return dp[0];
    }
};