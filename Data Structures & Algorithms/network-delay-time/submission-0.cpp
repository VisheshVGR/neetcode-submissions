class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Directed graph
        // shortest distance from source node

        // u -> {v, w}, {v, w}, ...
        vector<vector<pair<int, int>>> adjlist(n, vector<pair<int, int>>());

        for (auto &data : times)
        {
            // making 0-based indexing
            adjlist[data[0] - 1].push_back({data[1] - 1, data[2]});
        }

        // time to reach signal
        vector<int> time(n, INT_MAX);

        // {distance, node}
        // default is greater -> updating to smaller
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Init
        pq.push({0, k - 1});
        time[k - 1] = 0;

        while (!pq.empty())
        {
            int currtime = pq.top().first;
            int currnode = pq.top().second;

            pq.pop();

            // Relax adjacent nodes
            for (auto &nextnodedata : adjlist[currnode])
            {
                int nextnode = nextnodedata.first;
                int nextnodetime = nextnodedata.second;

                if (currtime + nextnodetime < time[nextnode])
                {
                    // we relax time here
                    time[nextnode] = currtime + nextnodetime;

                    pq.push({time[nextnode], nextnode});
                }
            }
        }

        int mx = INT_MIN;

        for (auto &t : time)
        {
            mx = max(mx, t);
        }

        return (mx == INT_MAX) ? -1 : mx;
    }
};