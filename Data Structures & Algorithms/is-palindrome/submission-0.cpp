class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size ();

        int i = 0;
        int j = s.size() - 1;

        while (true)
        {
            // skip non-alphanumeric chars
            while (i < n &&  isalnum(s[i]) == false)
                i++;

            while (j >= 0 && isalpha(s[j]) == false)
                j--;

            if (i >= j)
                break;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};
