class Solution
{
    int n;
    int m;

    vector<vector<int>> dp;

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        n = s.size();

        m = wordDict.size();

        dp.resize(n + 1, vector<int>(m + 1, -1));

        return dphelper(s, wordDict, n, m);
    }

private:
    bool dphelper(const string &str, const vector<string> &dict, int i, int j)
    {
        // string finished
        if (i == 0)
            return true;

        // dict finished
        if (j == 0)
            return false;

        int &memo = dp[i][j];

        if (memo != -1)
            return memo;

        // Cant use this word
        if (canUse(str, dict, i, j) == false)
        {
            return memo = dphelper(str, dict, i, j - 1);
        }
        else
        {
            // use, not use
            return memo = dphelper(str, dict, i - dict[j - 1].size(), m) || dphelper(str, dict, i, j - 1);
        }
    }

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