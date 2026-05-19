class DSU
{
private:
    vector<int> parent;

public:
    DSU(int n)
    {
        // Every one is their own parent
        parent.assign(n, -1);
    }

    bool Join(int a, int b)
    {
        int para = FindParent(a);
        int parb = FindParent(b);

        // Already in same component
        if (para == parb)
            return false;

        // Able to merge two components
        parent[parb] = para;

        return true;
    }

private:
    int FindParent(int n)
    {
        if (parent[n] == -1)
            return n;

        return parent[n] = FindParent(parent[n]);
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        /*
        We use PQ with min weight points
        and DSU to see if we formed graph
        */

        int n = points.size();

        DSU dsu(n + 1);

        // Map for {x,y} -> node
        int nodevalue = 1;

        map<pair<int, int>, int> mp;

        // min priority queue
        // distance, u, v
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Adding all points
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                if (mp[{x1, y1}] == 0)
                    mp[{x1, y1}] = nodevalue++;

                if (mp[{x2, y2}] == 0)
                    mp[{x2, y2}] = nodevalue++;

                int dist = abs(x1 - x2) + abs(y1 - y2);

                pq.push({dist, mp[{x1, y1}], mp[{x2, y2}]});
            }
        }

        int mincost = 0;

        while (!pq.empty())
        {
            auto &data = pq.top();

            int w = get<0>(data);
            int u = get<1>(data);
            int v = get<2>(data);

            pq.pop();

            if (dsu.Join(u, v))
            {
                // Was able to join
                mincost += w;
            }
        }

        return mincost;
    }
};