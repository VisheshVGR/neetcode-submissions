class Solution
{
    string answer = "0";

public:
    string multiply(string num1, string num2)
    {
        int n = num1.size();
        int m = num2.size();

        // Base case
        // If any one of string is zero
        if ((n == 1 && num1[0] == '0') || (m == 1 && num2[0] == '0'))
            return "0";

        // multiplying num2 digit by digit into num1
        // and adding it to final result
        for (int i = m - 1; i >= 0; i--)
        {
            string tempmul((m - 1) - i, '0');

            mul(tempmul, num1, n, num2[i]);

            answer = add(answer, tempmul);
        }

        return answer;
    }

private:
    void mul(string &output, const string &multiplyto, const int &n, const char &multiplywith)
    {
        if (multiplywith == '0')
        {
            output = "0";
            return;
        }

        int carry = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int num = (multiplyto[i] - '0') * (multiplywith - '0');
            num += carry;

            output.insert(output.begin(), (num % 10) + '0');
            carry = num / 10;
        }

        if (carry)
            output.insert(output.begin(), carry + '0');
    }

    string add(string num1, string num2)
    {
        string ans = "";

        int carry = 0;

        int n = num1.size();
        int m = num2.size();

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0)
        {
            int num = (num1[i] - '0') + (num2[j] - '0');

            num += carry;

            ans.insert(ans.begin(), (num % 10) + '0');
            carry = num / 10;

            i--;
            j--;
        }

        while (i >= 0)
        {
            int num = (num1[i] - '0') + carry;

            ans.insert(ans.begin(), (num % 10) + '0');
            carry = num / 10;

            i--;
        }

        while (j >= 0)
        {
            int num = (num2[j] - '0') + carry;

            ans.insert(ans.begin(), (num % 10) + '0');
            carry = num / 10;

            j--;
        }

        if (carry)
            ans.insert(ans.begin(), carry + '0');

        return ans;
    }
};