class Solution
{
public:
    int uniquePaths(int n, int m)
    {
        // go from top left to bottom right
        // by only taking right and bottom moves
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return helper(dp, 0, 0, n, m);
    }

private:
    int helper(vector<vector<int>> &dp, int i, int j, int n, int m)
    {
        if (i == n - 1 && j == m - 1)
            return 1;

        int &memo = dp[i][j];

        if (memo != -1)
            return memo;

        // if we are at right border -> can only go bottom
        if (j == m - 1)
            return memo = helper(dp, i + 1, j, n, m);

        // if we are at bottom border -> can only go right
        if (i == n - 1)
            return memo = helper(dp, i, j + 1, n, m);

        // we can go both right and bottom
        return memo = helper(dp, i + 1, j, n, m) + helper(dp, i, j + 1, n, m);
    }
};