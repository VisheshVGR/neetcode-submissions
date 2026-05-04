class Solution
{
    vector<vector<bool>> visited;

    int row;
    int col;

    int n;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        row = board.size();
        col = board[0].size();

        n = word.size();

        visited.assign(row, vector<bool>(col, false));

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                if (existHelper(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }

private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isValid(int i, int j)
    {
        if (i >= 0 && j >= 0 && i < row && j < col)
            return true;

        return false;
    }

    bool existHelper(vector<vector<char>> &board, string &word, int r, int c, int idx)
    {
        if (!isValid(r, c) || visited[r][c] || board[r][c] != word[idx])
            return false;

        // last character matched
        if (idx == n - 1)
            return true;

        visited[r][c] = true;

        for (int d = 0; d < 4; d++)
        {
            int newr = r + dx[d];
            int newc = c + dy[d];

            if (existHelper(board, word, newr, newc, idx + 1))
                return true;
        }

        visited[r][c] = false;
        
        return false;
    }
};