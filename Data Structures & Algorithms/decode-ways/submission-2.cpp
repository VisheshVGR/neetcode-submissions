class Solution
{
    vector<vector<int>> dp;

public:
    int numDecodings(string s)
    {
        /*
        A -> '1'
        Z -> '26'

        we will follow recursive approach
        if (CASE2)
            char has to be '1' or '2'

        if (CASE1)
            char has to be '1'

        // Case0:

        if (char is '0')
            it has to be followed by '1' or '2'     // CASE 2
        if (char is from '1' -> '6')
            we have 2 choice
            it has to be followed by '1' or '2'     // CASE 2
            OR
            it is an independent char               // CASE 0
        if (char if from '7' -> '9')
            we have 2 choice
            it has to be followed by '1'            // CASE 1
            OR
            it is an independent char               // CASE 0
        */

        int n = s.size();

        dp.assign(n + 1, vector<int>(3, -1));

        // Iterative approach

        // Base case
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i <= n; i++)
        {
            char ch = s[i - 1];

            for (int flag = 0; flag < 3; flag++)
            {
                // If CASE 1
                if (flag == 1)
                {
                    if (ch == '1')
                        dp[i][flag] = dp[i - 1][0];
                    else
                        dp[i][flag] = 0;

                    continue;
                }

                // If CASE 2
                if (flag == 2)
                {
                    if (ch == '1' || ch == '2')
                        dp[i][flag] = dp[i - 1][0];
                    else
                        dp[i][flag] = 0;

                    continue;
                }

                // If CASE 0
                if (ch == '0')
                {
                    dp[i][flag] = dp[i - 1][2];
                }

                if (ch >= '1' && ch <= '6')
                {
                    dp[i][flag] = dp[i - 1][2] + dp[i - 1][0];
                }

                if (ch >= '7' && ch <= '9')
                {
                    dp[i][flag] = dp[i - 1][1] + dp[i - 1][0];
                }
            }
        }

        return dp[n][0];
    }
};