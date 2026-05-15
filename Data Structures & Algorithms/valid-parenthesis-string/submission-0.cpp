class Solution {
public:
    bool checkValidString(string s) {
        /*
        '*' can be empty, open or closing
        */

        int n = s.size ();

        return dphelper (s, n, 0);
    }
private:
    bool dphelper (const string &str, int idx, int currval)
    {
        if (idx == 0)
        {
            if (currval == 0)
                return true;

            return false;
        }

        if (currval > 0)
            return false;

        if (str[idx - 1] == '(')
            return dphelper (str, idx - 1, currval + 1);

        if (str[idx - 1] == ')')
            return dphelper (str, idx - 1, currval - 1);

        // str is '*'

        // '*' can be '(' or ')' or empty string ''
        return dphelper (str, idx - 1, currval + 1) || dphelper (str, idx - 1, currval - 1) || dphelper (str, idx - 1, currval);
    }
};
