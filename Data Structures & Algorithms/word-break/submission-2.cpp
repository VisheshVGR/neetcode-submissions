class Solution
{
    int n;
    int m;

    vector<vector<bool>> dp;

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        n = s.size();

        m = wordDict.size();

        dp.resize(n + 1, vector<bool>(m + 1, -1));

        // Base case
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // Cant use this word
                if (canUse(s, wordDict, i, j) == false)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    // use, not use
                    dp[i][j] = dp[i - wordDict[j - 1].size()][m] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
private:
    bool canUse(const string &str, const vector<string> &dict, int i, int j)
    {
        // i is also str size
        const string &str2 = dict[j - 1];

        int n2 = str2.size();

        if (n2 > i)
            return false;

        for (int k = 0; k < n2; k++)
        {
            if (str[i - n2 + k] != str2[k])
                return false;
        }

        return true;
    }
};
