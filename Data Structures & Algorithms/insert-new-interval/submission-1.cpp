class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        /*

        */
        bool interval_inserted = false;

        vector<vector<int>> ans;

        int n = intervals.size();

        int s_new = newInterval[0];
        int e_new = newInterval[1];

        int idx = 0;

        while (idx < n)
        {
            if (interval_inserted)
            {
                ans.push_back(intervals[idx]);

                idx++;
                continue;
            }

            int s = intervals[idx][0];
            int e = intervals[idx][1];

            if (e < s_new)
            {
                ans.push_back(intervals[idx]);
            }
            else
            {
                interval_inserted = true;

                int start_of_merged = min(s, s_new);
                int end_of_merged;

                while (idx < n && intervals[idx][0] <= e_new)
                {
                    idx++;
                }

                idx--; // to go to merged interval

                if (idx == -1)
                {
                    // NewInterval is before first Interval
                    end_of_merged = e_new;
                }
                else
                {
                    end_of_merged = max(e_new, intervals[idx][1]);
                }

                ans.push_back({start_of_merged, end_of_merged});
            }

            idx++;
        }

        if (interval_inserted == false)
            ans.push_back(newInterval);

        return ans;
    }
};