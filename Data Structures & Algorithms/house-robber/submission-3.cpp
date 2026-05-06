class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        int last = nums[0];
        int secondlast = 0;
        int curr;

        for (int i = 2; i <= n; i++)
        {
            curr = max(
                nums[i - 1] + secondlast,
                last);

            secondlast = last;
            last = curr;
        }

        return max(curr, last);
    }
};