class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        int mx = nums[0];
        int curr = nums[0];

        for (int i = 1; i < n; i++)
        {
            curr = max(curr + nums[i], nums[i]);

            mx = max(mx, curr);
        }

        return mx;
    }
};