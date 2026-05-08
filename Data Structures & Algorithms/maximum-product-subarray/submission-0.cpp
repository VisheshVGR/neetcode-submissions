class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        // n <= 1000

        int mx = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int prod = 1;

            for (int j = i; j < n; j++)
            {
                prod *= nums[j];

                mx = max(mx, prod);
            }
        }

        return mx;
    }
};