class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        /*
        Observations:

        1) If all pos
        => Multiplication of all

        2) If even negative
        => Multiplication of all

        3) If odd negative
        excluding first neg -> max (left of first neg, right of first neg)
        excluding last neg ->  max (left of last neg, right of last neg)
        we need prefix and suffix mul for this

        4) If zeroes are there
        we break array in multiple where 0's occur
        */

        int n = nums.size();

        int prefix = 1;
        int suffix = 1;

        int maxprod = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;

            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];

            maxprod = max(maxprod, max (prefix, suffix));
        }

        return maxprod;
    }
};