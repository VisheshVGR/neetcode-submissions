class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {

        vector<vector<int>> adjlist(n, vector<int>());

        for (auto &edge : edges)
        {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        int comp = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            comp++;
            dfs(adjlist, visited, i);
        }

        return comp;
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