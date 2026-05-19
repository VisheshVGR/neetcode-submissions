class Solution
{
    /*
    we keep max pq
    if dist > top we dont add
    if dist <= top we add and remove top
    */
    double dist(double a, double b)
    {
        return sqrt((a * a) + (b * b));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<tuple<double, int, int>> pq;

        for (auto &p : points)
        {
            double currdistance = dist(p[0], p[1]);

            if (pq.size() < k)
            {
                pq.push({currdistance, p[0], p[1]});
            }
            else
            {
                double distoftop = get<0>(pq.top());

                if (currdistance <= distoftop)
                {
                    pq.push({currdistance, p[0], p[1]});

                    pq.pop();
                }
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty())
        {
            ans.push_back({get<1>(pq.top()), get<2>(pq.top())});

            pq.pop();
        }

        return ans;
    }
};