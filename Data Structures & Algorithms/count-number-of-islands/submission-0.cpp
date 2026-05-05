class Solution
{
    int row;
    int col;

public:
    int numIslands(vector<vector<char>> &grid)
    {
        row = grid.size();
        col = grid[0].size();

        int islandcount = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '0')
                    continue;

                // we found a land
                islandcount++;

                // fill dissolve this land
                fill(grid, i, j);
            }
        }

        return islandcount;
    }

private:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};

    bool isValid(int i, int j)
    {
        if (i >= 0 && j >= 0 && i < row && j < col)
            return true;

        return false;
    }

    void fill(vector<vector<char>> &grid, int r, int c)
    {
        // fill this land
        grid[r][c] = 0;

        // BFS to fill this island
        queue<pair<int, int>> q;

        q.push({r, c});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop ();

            int currr = p.first;
            int currc = p.second;

            // work on adjacent lands
            for (int d = 0; d < 4; d++)
            {
                int newr = currr + dx[d];
                int newc = currc + dy[d];

                if (isValid(newr, newc) && grid[newr][newc] == '1')
                {
                    // Not visited
                    grid[newr][newc] = '0';

                    q.push({newr, newc});
                }
            }
        }
    }
};