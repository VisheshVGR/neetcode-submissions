class Solution
{
    enum DIR
    {
        RIGHT = 0,
        DOWN = 1,
        LEFT = 2,
        UP = 3
    };

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        DIR dir = UP;
        int stepstotake;

        int i = 0;
        int j = -1;

        // To counter for initial position
        m += 1;

        while (n && m)
        {
            dir = DIR((dir + 1) % 4);

            if (dir == UP || dir == DOWN)
            {
                n--;
                stepstotake = n;
            }
            else
            {
                m--;
                stepstotake = m;
            }

            while (stepstotake)
            {
                switch (dir)
                {
                case RIGHT:
                    j++;
                    break;
                case DOWN:
                    i++;
                    break;
                case LEFT:
                    j--;
                    break;
                case UP:
                    i--;
                    break;
                default:
                    break;
                }

                ans.push_back(matrix[i][j]);

                stepstotake--;
            }
        }

        return ans;
    }
};