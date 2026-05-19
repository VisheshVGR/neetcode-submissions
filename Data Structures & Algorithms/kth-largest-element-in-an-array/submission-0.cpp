class Solution
{
    /*
    we keep min pq
    if dist > top we dont add
    if dist <= top we add and remove top
    */

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &p : nums)
        {
            if (pq.size() < k)
            {
                pq.push(p);
            }
            else
            {
                if (p >= pq.top())
                {
                    pq.push(p);

                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};
