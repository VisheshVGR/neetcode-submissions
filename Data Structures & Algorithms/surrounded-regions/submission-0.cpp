class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        /*
        convert O to X which are not surrounded
        O on border are not surrounded
        so every island which has any O on border is not surrounded
        else all are surrounded and should be converted to X

        we convert all island with O on border to I
        later
        we convert all O -> X and I -> O
        */

        // BFS from every border
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (board[i][j] != 'O')
                        continue;
                        
                    // I'm on border
                    board[i][j] = 'I';

                    q.push({i, j});
                }
            }
        }

        auto IsValid = [n, m](int i, int j)
        {
            if (i >= 0 && j >= 0 && i < n && j < m)
                return true;

            return false;
        };

        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int newx = x + dx[d];
                int newy = y + dy[d];

                if (IsValid(newx, newy) && board[newx][newy] == 'O')
                {
                    board[newx][newy] = 'I';

                    q.push({newx, newy});
                }
            }
        }

        // Post process
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == 'I')
                    board[i][j] = 'O';
            }
        }
    }
};