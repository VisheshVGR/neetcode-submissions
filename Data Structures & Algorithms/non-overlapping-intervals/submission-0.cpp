class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        /*
        we sort intervals
        we track interval by interval
        and if they are overlapping
        we remove the one which has greater end,
        as that would be overlapping with other more
        */

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int end = intervals[0][1];

        int deleted = 0;

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < end)
            {
                deleted++;
                // we update our end to
                end = min(end, intervals[i][1]);
            }
            else
            {
                // Not over lapping

                // we update our end to next end
                end = intervals[i][1];
            }
        }

        return deleted;
    }
};