class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();

        // Sort position in ascending and speed accordingly
        // position, speed
        vector<pair<int, int>> data;

        for (int i = 0; i < n; i++)
        {
            data.push_back({position[i], speed[i]});
        }

        // All positions are unique
        sort(data.begin(), data.end(), [](auto a, auto b)
             { return a.first < b.first; });

        double time_to_target = 0;

        int fleet = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            double distleft = target - data[i].first;
            double curr_time = distleft / data[i].second;

            if (curr_time > time_to_target)
            {
                fleet++;
                time_to_target = curr_time;
            }
        }

        return fleet;
    }
};