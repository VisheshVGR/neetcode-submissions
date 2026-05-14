class Solution
{
public:
    double myPow(double x, int n)
    {
        bool IsPowerNeg = false;

        if (n < 0)
        {
            IsPowerNeg = true;
            n = -n;
        }

        double ans = 1;

        while (n)
        {
            if (n & 1)
                ans = ans * x;

            x = x * x;

            n >>= 1;
        }

        if (IsPowerNeg)
            return 1 / ans;

        return ans;
    }
};