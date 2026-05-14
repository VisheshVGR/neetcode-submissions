class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        // Adding 1 to digits
        digits[n - 1] += 1;

        vector<int> ans;

        int carry = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int num = digits[i] + carry;

            carry = num / 10;

            ans.push_back(num % 10);
        }

        if (carry)
            ans.push_back(1);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
