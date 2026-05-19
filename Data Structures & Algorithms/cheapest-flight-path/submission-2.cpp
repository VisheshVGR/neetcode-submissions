class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        /*
        get adj list on flights

        from src we do BFS upto k times
        */

        // u -> {v, w}, {v, w}
        vector<vector<pair<int, int>>> adjlist(n, vector<pair<int, int>>());

        for (auto &data : flights)
        {
            adjlist[data[0]].push_back({data[1], data[2]});
        }

        // distance
        int dist_to_dst = INT_MAX;

        // priority queue: weight, node, stops
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, src, 0});

        while (!pq.empty())
        {
            int nodes = pq.size();

            while (nodes--)
            {
                auto &data = pq.top();

                int currweight = get<0>(data);
                int currnode = get<1>(data);
                int currstops = get<2>(data);

                pq.pop();

                // adj nodes

                for (auto &data : adjlist[currnode])
                {
                    int nextnodeweight = data.second;
                    int nextnode = data.first;

                    if (currstops <= k)
                    {
                        if (nextnode == dst)
                        {
                            dist_to_dst = min(dist_to_dst, currweight + nextnodeweight);
                        }
                        else
                        {
                            if (currweight + nextnodeweight < dist_to_dst)
                                pq.push({currweight + nextnodeweight, nextnode, currstops + 1});                        }
                    }
                }
            }
        }

        return (dist_to_dst == INT_MAX) ? -1 : dist_to_dst;
    }
};