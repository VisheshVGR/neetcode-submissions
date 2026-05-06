class Solution
{
    static const int DIR = 4;
    int dx[DIR] = {-1, 0, 0, 1};
    int dy[DIR] = {0, -1, 1, 0};

    int row;
    int col;

    vector<vector<bool>> visited;
    vector<vector<bool>> possiblefrompacific;

    vector<vector<int>> answer;

    bool IsValid(int i, int j)
    {
        if (i >= 0 && j >= 0 && i < row && j < col)
            return true;

        return false;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        row = heights.size();
        col = heights[0].size();

        visited.assign(row, vector<bool>(col, false));
        possiblefrompacific.assign(row, vector<bool>(col, false));

        // DS for BFS
        queue<pair<int, int>> q;

        // First round -> BFS from pacific

        // Init -> first row
        for (int c = 0; c < col; c++)
        {
            q.push({0, c});

            visited[0][c] = true;
            possiblefrompacific[0][c] = true;
        }

        // Init -> first col except 1st elem
        for (int r = 1; r < row; r++)
        {
            q.push({r, 0});

            visited[r][0] = true;
            possiblefrompacific[r][0] = true;
        }

        // BFS -> FIRST ROUND
        while (!q.empty())
        {
            auto &data = q.front();
            q.pop();

            int r = data.first;
            int c = data.second;

            // See next possible location
            for (int d = 0; d < DIR; d++)
            {
                int newr = r + dx[d];
                int newc = c + dy[d];

                // new pos is valid + not visited before + greater or equal than curr
                if (IsValid(newr, newc) && !visited[newr][newc] && (heights[newr][newc] >= heights[r][c]))
                {
                    q.push({newr, newc});

                    visited[newr][newc] = true;
                    possiblefrompacific[newr][newc] = true;
                }
            }
        }

        // Second round -> BFS from pacific

        // Second Round INIT
        visited.assign(row, vector<bool>(col, false));

        // Init -> last row
        for (int c = 0; c < col; c++)
        {
            q.push({row - 1, c});

            visited[row - 1][c] = true;

            if (possiblefrompacific[row - 1][c] == true)
                answer.push_back({row - 1, c});
        }

        // Init -> first col except 1st elem
        for (int r = 0; r < row - 1; r++)
        {
            q.push({r, col - 1});

            visited[r][col - 1] = true;

            if (possiblefrompacific[r][col - 1] == true)
                answer.push_back({r, col - 1});
        }

        // BFS -> SECOND ROUND
        while (!q.empty())
        {
            auto &data = q.front();
            q.pop();

            int r = data.first;
            int c = data.second;

            // See next possible location
            for (int d = 0; d < DIR; d++)
            {
                int newr = r + dx[d];
                int newc = c + dy[d];

                // new pos is valid + not visited before + greater or equal than curr
                if (IsValid(newr, newc) && !visited[newr][newc] && (heights[newr][newc] >= heights[r][c]))
                {
                    q.push({newr, newc});

                    visited[newr][newc] = true;

                    if (possiblefrompacific[newr][newc] == true)
                        answer.push_back({newr, newc});
                }
            }
        }

        return answer;
    }
};
