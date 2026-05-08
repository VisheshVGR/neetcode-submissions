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

        return prodhelper(nums, 0, n - 1);
    }

private:
    int prodhelper(const vector<int> &nums, int l, int r)
    {
        // INVLAID WINDOW
        if (l > r)
            return INT_MIN;

        if (l == r)
            return nums[l];

        int prodofall = 1;
        int countofneg = 0;
        bool haszeroes = false;

        for (int i = l; i <= r; i++)
        {
            prodofall *= nums[i];

            if (nums[i] == 0)
            {
                haszeroes = true;
                break;
            }

            if (nums[i] < 0)
                countofneg++;
        }

        if (haszeroes)
        {
            int maxprod = 0;
            int boundarystart = l;

            for (int i = l; i <= r; i++)
            {
                if (nums[i] == 0)
                {
                    maxprod = max(maxprod, prodhelper(nums, boundarystart, i - 1));

                    boundarystart = i + 1;
                }
            }
            
            // For last boundry
            maxprod = max(maxprod, prodhelper(nums, boundarystart, r));

            return maxprod;
        }

        // No zeroes found
        if (countofneg % 2 == 0)
        {
            // Either we have zero neg or even numbers of neg
            // we can consider multiplying all numbers
            return prodofall;
        }

        // We need to work using prefix and suffix of negs
        int n = r - l + 1;

        vector<int> prefix(n + 2), suffix(n + 2);

        // Building prefix
        prefix[0] = 1;

        for (int i = l; i <= r; i++)
            prefix[i - l + 1] = prefix[i - 1 - l + 1] * nums[i];

        // Building suffix
        suffix[n + 1] = 1;

        for (int i = r; i >= l; i--)
            suffix[i - l + 1] = suffix[i + 1 - l + 1] * nums[i];

        int maxprod = 1;

        for (int i = 1; i <= n; i++)
            maxprod = max(maxprod, max(prefix[i - 1], suffix[i + 1]));

        return maxprod;
    }
};