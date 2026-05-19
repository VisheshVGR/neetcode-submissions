class Solution
{
    priority_queue<int> pq;

public:
    int lastStoneWeight(vector<int> &stones)
    {
        /*
        pick 2 heavier stones a, b

        if (a == b)
            both gets destroyed

        else
            smaller gets destroyed
            other gets added back with abs (a - b)
        */

        for (auto &s : stones)
            pq.push(s);

        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            if (a == b)
                continue;

            pq.push(abs(a - b));
        }

        if (pq.size() == 0)
            return 0;

        return pq.top();
    }
};