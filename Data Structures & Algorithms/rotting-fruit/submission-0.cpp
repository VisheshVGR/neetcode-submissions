
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        /*
        0 representing an empty cell
        1 representing a fresh fruit
        2 representing a rotten fruit
        */

        int n = grid.size();
        int m = grid[0].size();

        int freshfruitcount = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    freshfruitcount++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int minutes = 0;

        // Helper
        auto IsValid = [&n, &m](int i, int j)
        {
            if (i >= 0 && i < n && j >= 0 && j < m)
                return true;

            return false;
        };

        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};

        while (freshfruitcount != 0 && !q.empty())
        {
            // fruits
            int rottenfruitcnt = q.size();

            minutes++;

            while (rottenfruitcnt--)
            {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                // check for adjacent fresh fruits
                for (int d = 0; d < 4; d++)
                {
                    int newx = x + dx[d];
                    int newy = y + dy[d];

                    if (IsValid(newx, newy) && grid[newx][newy] == 1)
                    {
                        grid[newx][newy] = 2;

                        freshfruitcount--;

                        q.push({newx, newy});
                    }
                }
            }
        }

        if (freshfruitcount == 0)
            return minutes;

        return -1;
    }
};
