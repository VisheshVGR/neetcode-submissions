class Solution {
public:

    /*
    ... + str.size () + '#' + str  + ...
    */

    string encode(vector<string>& strs) {
        string encodedstring = "";

        int n = strs.size ();

        if (n == 0)
            return "";

        int len = 0;

        for (int i = 0; i < n; i++)
        {
            len = strs[i].size ();

            encodedstring += to_string (len);
            encodedstring += '#';

            encodedstring += strs[i];
        }

        return encodedstring;
    }

    vector<string> decode(string s) {
        int n = s.size ();

        if (n == 0)
            return {};

        vector<string> ans;

        int i = 0;

        string str;
        int len;

        while (i < n)
        {
            len = 0;
            
            while (s[i] != '#')
            {
                len = (10 * len) + (s[i] - '0');

                i++;
            }

            // Skipping special character
            i++;

            str = s.substr (i, len);

            ans.push_back (str);

            i += len;
        }

        return ans;
    }
};
