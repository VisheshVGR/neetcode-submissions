class Solution
{
    int n;
    int m;

    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    vector<vector<bool>> visited;

    bool IsValid(int i, int j)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;

        return false;
    }

    int mxarea = 0;

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    continue;

                if (visited[i][j] == true)
                    continue;

                mxarea = max(mxarea, fill(grid, i, j));
            }
        }

        return mxarea;
    }

private:
    int fill(vector<vector<int>> &grid, int x, int y)
    {
        int cnt = 1; // for current node

        visited[x][y] = true;

        for (int d = 0; d < 4; d++)
        {
            int newx = x + dx[d];
            int newy = y + dy[d];

            if (IsValid(newx, newy) && grid[newx][newy] == 1 && visited[newx][newy] == false)
            {
                visited[newx][newy] = true;

                // process this node
                cnt += fill(grid, newx, newy);
            }
        }

        return cnt;
    }
};
