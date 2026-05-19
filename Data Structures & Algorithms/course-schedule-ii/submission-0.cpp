class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Link from 'b' -> 'a'

        // Find order
        // we will use InOrder technique

        vector<int> inorder(numCourses, 0);

        vector<vector<int>> adjlist(numCourses, vector<int>());

        int edges = 0;

        for (auto &data : prerequisites)
        {
            adjlist[data[1]].push_back(data[0]);

            edges++;

            inorder[data[0]]++;
        }

        queue<int> q;

        vector<int> order;

        for (int i = 0; i < numCourses; i++)
        {
            if (inorder[i] == 0)
            {
                q.push(i);

                order.push_back(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &nextnode : adjlist[node])
            {
                inorder[nextnode]--;
                edges--;
                if (inorder[nextnode] == 0)
                {
                    order.push_back(nextnode);

                    q.push(nextnode);
                }
            }
        }

        if (edges > 0)
            return {};

        return order;
    }
};