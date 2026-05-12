class Solution {
    static const int n = 9;

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> f;
        // check each row

        for (int r = 0; r < n; r++) {
            f.assign(10, false);

            for (int c = 0; c < n; c++) {
                if (board[r][c] == '.') continue;

                // two same number found
                if (f[board[r][c] - '0'] == true) return false;

                f[board[r][c] - '0'] = true;
            }
        }

        // check each col
        for (int c = 0; c < n; c++) {
            f.assign(10, false);

            for (int r = 0; r < n; r++) {
                if (board[r][c] == '.') continue;

                // two same number found
                if (f[board[r][c] - '0'] == true) return false;

                f[board[r][c] - '0'] = true;
            }
        }

        // check each 9*9 box
        for (int r = 0; r < n; r += 3) {
            for (int c = 0; c < n; c += 3) {
                f.assign(10, false);

                if (board[r][c] != '.') {
                    // two same number found
                    if (f[board[r][c] - '0'] == true) return false;
                    f[board[r][c] - '0'] = true;
                }

                if (board[r][c + 1] != '.') {
                    // two same number found
                    if (f[board[r][c + 1] - '0'] == true) return false;
                    f[board[r][c + 1] - '0'] = true;
                }

                if (board[r][c + 2] != '.') {
                    // two same number found
                    if (f[board[r][c + 2] - '0'] == true) return false;
                    f[board[r][c + 2] - '0'] = true;
                }

                if (board[r + 1][c] != '.') {
                    // two same number found
                    if (f[board[r + 1][c] - '0'] == true) return false;
                    f[board[r + 1][c] - '0'] = true;
                }

                if (board[r + 1][c + 1] != '.') {
                    // two same number found
                    if (f[board[r + 1][c + 1] - '0'] == true) return false;
                    f[board[r + 1][c + 1] - '0'] = true;
                }

                if (board[r + 1][c + 2] != '.') {
                    // two same number found
                    if (f[board[r + 1][c + 2] - '0'] == true) return false;
                    f[board[r + 1][c + 2] - '0'] = true;
                }

                if (board[r + 2][c] != '.') {
                    // two same number found
                    if (f[board[r + 2][c] - '0'] == true) return false;
                    f[board[r + 2][c] - '0'] = true;
                }

                if (board[r + 2][c + 1] != '.') {
                    // two same number found
                    if (f[board[r + 2][c + 1] - '0'] == true) return false;
                    f[board[r + 2][c + 1] - '0'] = true;
                }

                if (board[r + 2][c + 2] != '.') {
                    // two same number found
                    if (f[board[r + 2][c + 2] - '0'] == true) return false;
                    f[board[r + 2][c + 2] - '0'] = true;
                }
            }
        }

        return true;
    }
};