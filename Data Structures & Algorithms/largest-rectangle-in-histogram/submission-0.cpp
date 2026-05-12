class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        /*
        for each bar
        we will find
        next smaller
        and prev smaller

        for next smaller and prev smaller
        we will use monotonic stack
        */

        int n = heights.size();

        // val, idx
        stack<pair<int, int>> nextsmaller;
        stack<pair<int, int>> prevsmaller;

        // idx
        vector<int> nextsmalleridx(n);
        vector<int> prevsmalleridx(n);

        // Init
        nextsmaller.push({-1, n});
        prevsmaller.push({-1, -1});

        int val;

        // Building nextsmalleridx and prevsmalleridx
        for (int i = 0; i < n; i++)
        {
            // Prev smaller
            val = heights[i];

            while (val <= prevsmaller.top().first)
            {
                prevsmaller.pop();
            }

            prevsmalleridx[i] = prevsmaller.top().second;

            prevsmaller.push({val, i});

            // Next smaller
            val = heights[n - 1 - i];

            while (val <= nextsmaller.top().first)
            {
                nextsmaller.pop();
            }

            nextsmalleridx[n - 1 - i] = nextsmaller.top().second;

            nextsmaller.push({val, n - 1 - i});
        }

        int maxarea = 0;

        for (int i = 0; i < n; i++)
        {
            // height * (nextsmalleridx[i] - prevsmalleridx[i] - 1)

            maxarea = max(maxarea, heights[i] * (nextsmalleridx[i] - prevsmalleridx[i] - 1));
        }

        return maxarea;
    }
};