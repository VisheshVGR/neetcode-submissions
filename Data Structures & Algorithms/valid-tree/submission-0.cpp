class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        /*
        According to the definition of a tree, a tree is an undirected graph with no cycles,
        all the nodes are connected as one component, and any two nodes have exactly one path.


        // Should be one component
        // no cycle

        */

        // Base case if we have edges not equal to n - 1 nodes, we can't have a valid tree
        if (n - 1 != edges.size())
            return false;

        // create adjacency list

        // do dfs from one node
        // if we able to visit all nodes
        // we have valid tree

        vector<vector<int>> adjlist(n, vector<int>());

        for (auto &edge : edges)
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        dfs(adjlist, visited, 0);

        for (auto val : visited)
            if (!val)
                return false;

        return true;
    }

private:
    void dfs(vector<vector<int>> &adjlist, vector<bool> &visited, int curr)
    {
        visited[curr] = true;

        for (auto &child : adjlist[curr])
        {
            if (!visited[child])
                dfs(adjlist, visited, child);
        }
    }
};