class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        vector<int> dp(n + 1);

        // we start from 0-th or 1-st stair so we incurr zero cost
        dp[0] = dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            // for each stair, we can come from last or 2nd last stair
            // incurring cost to reach that stair plus cost to move from that stair
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};