class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        vector<vector<int>> interval(2, vector<int>(1005, 0));

        for (auto &data : intervals)
        {
            interval[0][data[0]]++;
            interval[1][data[1]]--;
        }

        int currsum = 0;

        int startpoint = -1;
        int endpoint = -1;

        for (int i = 0; i < 1005; i++)
        {
            currsum += interval[0][i];

            if (currsum != 0 && startpoint == -1)
                startpoint = i;

            currsum += interval[1][i];

            if (currsum == 0 && startpoint != -1)
            {
                endpoint = i;

                ans.push_back({startpoint, endpoint});

                startpoint = -1;
                endpoint = -1;
            }
        }

        return ans;
    }
};