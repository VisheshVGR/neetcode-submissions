class MedianFinder
{
    // Max heap
    priority_queue<int> maxpq;
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minpq;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        int top;

        while (maxpq.empty() == false && maxpq.top() > num)
        {
            // Shift elem from maxpq to minpq
            top = maxpq.top();
            maxpq.pop();

            minpq.push(top);
        }

        minpq.push(num);

        // minpq should have either equal or one elem greater than maxpq
        while (minpq.size() > maxpq.size() + 1)
        {
            // Normalize
            // Shift elem from minpq to maxpq
            int top = minpq.top();
            minpq.pop();

            maxpq.push(top);
        }
    }

    double findMedian()
    {
        if ((minpq.size() + maxpq.size()) % 2 == 0)
        {
            return ((double)minpq.top() + (double)maxpq.top()) / 2;
        }
        else
        {
            return (double)minpq.top();
        }
    }
};
