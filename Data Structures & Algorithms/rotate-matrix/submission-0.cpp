class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int iteration = 0; iteration < n / 2; iteration++)
        {
            for (int i = iteration; i < n - iteration - 1; i++)
            {
                int temp = matrix[iteration][i];

                matrix[iteration][i] = matrix[n - 1 - i][iteration];

                matrix[n - 1 - i][iteration] = matrix[n - 1 - iteration][n - 1 - i];

                matrix[n - 1 - iteration][n - 1 - i] = matrix[i][n - 1 - iteration];

                matrix[i][n - 1 - iteration] = temp;
            }
        }
    }
};
