class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(), [](auto a, auto b)
             {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0]; });

        int s = intervals[0][0];
        int e = intervals[0][1];

        for (int i = 1; i <= n; i++)
        {
            if (i == n)
            {
                ans.push_back({s, e});
                break;
            }

            if (intervals[i][0] <= e)
            {
                e = max(e, intervals[i][1]);
            }
            else
            {
                ans.push_back({s, e});

                s = intervals[i][0];
                e = intervals[i][1];
            }
        }

        return ans;
    }
};