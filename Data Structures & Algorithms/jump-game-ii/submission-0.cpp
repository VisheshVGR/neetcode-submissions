class Solution
{
public:
    int jump(vector<int> &nums)
    {
        /*
        initially we take 0 jump to reach 0
        and INF jump to reach other dist

        from start to last we check

        for each nums[i]
        we can jump min (jump[i] + 1, jump[i])

        */
        int n = nums.size();

        vector<int> jumps(n, INT_MAX / 2);

        jumps[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++)
            {
                jumps[j] = min(jumps[j], jumps[i] + 1);
            }
        }

        return jumps[n - 1];
    }
};