class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp;
        dp.assign(n + 1, vector<int>(m + 1, -1));

        return dphelper(dp, text1, text2, n, m);
    }

private:
    int dphelper(vector<vector<int>> &dp, const string &text1, const string &text2, int i, int j)
    {
        if (i == 0 || j == 0)
            return 0;

        int &memo = dp[i][j];

        if (memo != -1)
            return memo;

        if (text1[i - 1] == text2[j - 1])
            return memo = 1 + dphelper(dp, text1, text2, i - 1, j - 1);
        else
            return memo = max(dphelper(dp, text1, text2, i - 1, j), dphelper(dp, text1, text2, i, j - 1));
    }
};