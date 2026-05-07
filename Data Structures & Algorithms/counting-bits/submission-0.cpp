class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;

        for (int i = 0; i <= n; i++)
            ans.push_back(hammingWeight(i));

        return ans;
    }

private:
    int hammingWeight(int n)
    {
        int cnt = 0;

        while (n)
        {
            cnt++;
            n = (n & (n - 1));
        }

        return cnt;
    }
};