class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        /*
        we use dequeue

        if greater than top
        we remove all and keep only num
        else we add to back
        */

        deque<int> q;
        int n = nums.size();

        // First window
        for (int i = 0; i < k; i++)
        {
            if (q.size() == 0)
            {
                q.push_front(nums[i]);
            }
            else if (nums[i] > q.front())
            {
                q.clear();

                q.push_front(nums[i]);
            }
            else
            {
                while (q.back() < nums[i])
                    q.pop_back();

                q.push_back(nums[i]);
            }
        }

        vector<int> ans;

        ans.push_back(q.front());

        for (int i = k; i < n; i++)
        {
            // remove elem
            if (q.front() == nums[i - k])
                q.pop_front();

            // add elem
            if (nums[i] > q.front())
            {
                q.clear();

                q.push_front(nums[i]);
            }
            else
            {
                while (q.back() < nums[i])
                    q.pop_back();

                q.push_back(nums[i]);
            }

            ans.push_back(q.front());
        }

        return ans;
    }
};