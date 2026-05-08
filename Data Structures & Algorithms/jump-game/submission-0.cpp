class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        return dphelper(nums, 0, n);
    }

private:
    bool dphelper(const vector<int> &nums, int i, const int &n)
    {
        if (i >= n - 1)
            return true;

        for (int jump = 1; jump <= nums[i]; jump++)
        {
            if (dphelper(nums, i + jump, n))
                return true;
        }

        return false;
    }
};