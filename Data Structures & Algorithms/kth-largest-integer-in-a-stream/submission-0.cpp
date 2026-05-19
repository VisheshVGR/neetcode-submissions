class KthLargest
{
    /*
    We use min-heap of k-th size

    we fill k elems

    now for each elem

    if elem is less than top -> ignore
    else -> add elem -> remove top

    top will always be k-th smallest elem
    */

    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;

public:
    KthLargest(int k, vector<int> &nums)
    {

        limit = k;

        for (auto &num : nums)
            add(num);
    }

    int add(int val)
    {
        pq.push(val);

        if (pq.size() > limit)
            pq.pop();

        return pq.top();
    }
};