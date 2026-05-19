class Solution
{
public:
    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        /*
        -1 cannot traverse
        0  chest
        INF can traverse

        // fill each cell with nearest chest
        */

        // Soln: BFS from each chest
        int n = grid.size();
        int m = grid[0].size();

        // i, j, weight
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.emplace(i, j);
                }
            }
        }

        auto IsValid = [n, m](int i, int j)
        {
            if (i >= 0 && i < n && j >= 0 && j < m)
            {
                return true;
            }

            return false;
        };

        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {-1, 0, 0, 1};

        // BFS from each location
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int newx = x + dx[d];
                int newy = y + dy[d];

                if (IsValid(newx, newy) && grid[newx][newy] == INT_MAX)
                {
                    grid[newx][newy] = grid[x][y] + 1;

                    q.push({newx, newy});
                }
            }
        }
    }
};