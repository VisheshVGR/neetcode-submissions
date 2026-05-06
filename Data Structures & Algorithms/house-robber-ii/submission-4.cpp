class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        // Special case
        if (n == 1)
            return nums[0];

        // Base cases
        int secondlast_cannotrob = 0;
        int secondlast_canrob = 0;

        int last_cannotrob = 0;
        int last_canrob = nums[0];

        int curr_canrob;
        int curr_cannotrob;

        for (int i = 2; i <= n; i++)
        {
            // Cannot rob
            curr_cannotrob = max(nums[i - 1] + secondlast_cannotrob, last_cannotrob);

            secondlast_cannotrob = last_cannotrob;
            last_cannotrob = curr_cannotrob;

            // Can rob
            curr_canrob = max(nums[i - 1] + secondlast_canrob, last_canrob);

            secondlast_canrob = last_canrob;
            last_canrob = curr_canrob;
        }

        // Because olderstates are updated

        return max(last_cannotrob, secondlast_canrob);
    }
};