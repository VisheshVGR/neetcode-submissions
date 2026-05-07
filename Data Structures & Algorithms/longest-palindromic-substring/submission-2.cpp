class Solution
{
public:
    string longestPalindrome(string s)
    {
        /*
        single char is always a palindrome
        palindrome can be of odd size or even size

        we start with dp table
        for odd we see
        if i == j,
            if dp[i + 1][j - 1] != 0
                dp[i][j] = 1 + dp[i + 1][j - 1]
        else 0

        for even we see
        if i == j,
            if dp[i + 1][j - 1] != 0
                dp[i][j] = 1 + dp[i + 1][j - 1]
        else 0
        */

        int n = s.size();

        // Base case
        if (n == 1)
            return s;

        vector<vector<int>> dp(n, vector<int>(n));

        int maxlen = 1;
        int maxstartpoint = 1;

        // for single char
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // for two char
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 2;

                maxlen = 2;
                maxstartpoint = i;
            }
            else
            {
                dp[i][i + 1] = 0;
            }
        }

        // for other length (> 3) substring
        for (int len = 3; len <= n; len++)
        {
            for (int startpoint = 0; startpoint < n - len + 1; startpoint++)
            {
                int endpoint = startpoint + len - 1;

                if (s[startpoint] == s[endpoint] && dp[startpoint + 1][endpoint - 1] != 0)
                {
                    dp[startpoint][endpoint] = 2 + dp[startpoint + 1][endpoint - 1];

                    if (dp[startpoint][endpoint] > maxlen)
                    {
                        maxlen = dp[startpoint][endpoint];
                        maxstartpoint = startpoint;
                    }
                }
                else
                {
                    dp[startpoint][endpoint] = 0;
                }
            }
        }

        return s.substr(maxstartpoint, maxlen);
    }
};