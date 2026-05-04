class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        /*
        We solve problem for each char 'a'->'z'

        we will use sliding window
        i = j = 0;

        keep count of valid char
        keep count of invalid char

        if invalid char > limit
        we shrink window
        */

        int mx = 0;
        int n = s.size();

        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            mx = max(mx, helper(ch, s, n, k));
        }

        return mx;
    }

private:
    int helper(char validchar, const string &str, const int &n, const int &k)
    {
        int maxlen = 0;

        int l = 0, r = 0;
        int validcnt = 0;
        int invalidcnt = 0;

        while (r < n)
        {
            // add one char to window
            if (str[r] == validchar)
                validcnt++;
            else
                invalidcnt++;

            // remove chars if window become invalid
            while (invalidcnt > k)
            {
                if (str[l] == validchar)
                    validcnt--;
                else
                    invalidcnt--;

                l++;
            }

            // update maxlen
            maxlen = max(maxlen, validcnt + invalidcnt);

            // operate next char
            r++;
        }

        return maxlen;
    }
};
