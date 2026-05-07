class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();

        // Base case
        if (n == 1)
            return 1;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // for single char
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // for two char
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 2;
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
                }
                else
                {
                    dp[startpoint][endpoint] = 0;
                }
            }
        }

        int ans = 0;

        for (auto &row : dp)
        {
            for (auto &val : row)
            {
                if (val > 0)
                    ans++;
            }
        }

        return ans;
    }
};