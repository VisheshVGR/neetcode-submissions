class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = 0;

        int bit = 0;
        int carry = 0;

        while (bit < 32)
        {
            int bit_a = a & (1 << bit);
            int bit_b = b & (1 << bit);

            if (carry)
            {
                if (bit_a && bit_b)
                {
                    sum |= (1 << bit);
                    carry = 1;
                }
                else if ((bit_a && !bit_b) || (!bit_a && bit_b))
                {
                    sum |= (0 << bit);
                    carry = 1;
                }
                else
                {
                    sum |= (1 << bit);
                    carry = 0;
                }
            }
            else
            {
                if (bit_a && bit_b)
                {
                    sum |= (0 << bit);
                    carry = 1;
                }
                else if ((bit_a && !bit_b) || (!bit_a && bit_b))
                {
                    sum |= (1 << bit);
                    carry = 0;
                }
                else
                {
                    sum |= (0 << bit);
                    carry = 0;
                }
            }

            bit++;
        }

        return sum;
    }
};
