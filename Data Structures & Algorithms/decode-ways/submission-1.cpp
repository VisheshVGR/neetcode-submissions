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

        return dphelper(s, n, 0);
    }

private:
    int dphelper(const string &str, int n, int flag)
    {
        // no more char left
        if (n == 0)
        {
            if (flag == 0)
                return 1;
            else
                return 0;
        }

        int &memo = dp[n][flag];

        if (memo != -1)
            return memo;

        char ch = str[n - 1];

        // If CASE 1
        if (flag == 1)
        {
            if (ch == '1')
                return memo = dphelper(str, n - 1, 0);
            else
                return 0;
        }

        // If CASE 2
        if (flag == 2)
        {
            if (ch == '1' || ch == '2')
                return memo = dphelper(str, n - 1, 0);
            else
                return 0;
        }

        // If CASE 0
        // if (char is '0')
        //     it has to be followed by '1' or '2'     // CASE 2
        if (ch == '0')
        {
            return memo = dphelper(str, n - 1, 2);
        }

        // if (char is from '1' -> '6')
        //     we have 2 choice
        //     it has to be followed by '1' or '2'     // CASE 2
        //     OR
        //     it is an independent char               // CASE 0
        if (ch >= '1' && ch <= '6')
        {
            return memo = dphelper(str, n - 1, 2) + dphelper(str, n - 1, 0);
        }

        // if (char if from '7' -> '9')
        //     we have 2 choice
        //     it has to be followed by '1'            // CASE 1
        //     OR
        //     it is an independent char               // CASE 0
        if (ch >= '7' && ch <= '9')
        {
            return memo = dphelper(str, n - 1, 1) + dphelper(str, n - 1, 0);
        }

        return INT_MIN; // Should never reach here
    }
};