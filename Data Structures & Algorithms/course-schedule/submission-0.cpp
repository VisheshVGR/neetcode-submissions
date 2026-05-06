class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        /*
        we make adjacency list of nodes
        for each node we get in-node count
        we start with nodes whose in-node count is zero
        those are courses we can start without any pre-requisite
        form these courses we see which all courses we can complete
        and if course which this can completes, becomes in-node == 0, we recursively see what all courses this new coures can allow

        in the end if there are still courses for which in-node > 0, we can't complete all courses
        */

        vector<vector<int>> adjlist(numCourses, vector<int>());

        vector<int> innode(numCourses, 0);

        for (auto &data : prerequisites)
        {
            // prerequisites[i] = [a, b] indicates that you must take course b first if you want to take course a
            adjlist[data[1]].push_back(data[0]);

            innode[data[0]]++;
        }

        // DFS from all courses which don't need pre-requisite
        queue<int> q;

        for (int c = 0; c < numCourses; c++)
        {
            if (innode[c] == 0)
                q.push(c);
        }

        while (!q.empty())
        {
            int c = q.front();
            q.pop();

            // see if next courses can be taken
            for (auto &nextcourse : adjlist[c])
            {
                innode[nextcourse]--;

                if (innode[nextcourse] == 0)
                    q.push(nextcourse);
            }
        }

        for (auto &val : innode)
            if (val > 0)
                return false;

        return true;
    }
};