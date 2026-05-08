class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // If mat[i][j] == 0
        // set ith row and jth col to zero

        // we will use efficient technique to mark 0th row and col to 0

        int n = matrix.size();
        int m = matrix[0].size();

        int firstrowvalue = 1;
        int firstcolvalue = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        firstrowvalue = 0;

                    if (j == 0)
                        firstcolvalue = 0;

                    if (i != 0 && j != 0)
                        matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }

        // fill rows
        for (int r = 1; r < n; r++)
        {
            if (matrix[r][0] != 0)
                continue;

            // fill this col
            for (int i = 0; i < m; i++)
                matrix[r][i] = 0;
        }

        // fill col
        for (int c = 1; c < m; c++)
        {
            if (matrix[0][c] != 0)
                continue;

            // fill this col
            for (int i = 0; i < n; i++)
                matrix[i][c] = 0;
        }

        // fill 0th row
        if (firstrowvalue == 0)
            for (int c = 0; c < m; c++)
                matrix[0][c] = 0;

        // fill 0th col
        if (firstcolvalue == 0)
            for (int r = 0; r < n; r++)
                matrix[r][0] = 0;
    }
};