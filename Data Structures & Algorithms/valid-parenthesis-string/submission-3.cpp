class Solution
{
public:
    bool checkValidString(string s)
    {
        /*
        we maintain low and high score
        for s == '(' we increase high and low score by 1
        for s == ')' we decrease high and low score by 1
        for s == '*' we increase high by 1 and decrease low by 1

        if at the end, our range includes 0
        means we could have used wildcard to reach result
        */

        int low = 0;
        int high = 0;

        for (auto &ch : s)
        {
            if (ch == '(')
            {
                high++;
                low++;
            }
            else if (ch == ')')
            {
                high--;
                low--;
            }
            else
            {
                high++;
                low--;

                // If using wildcard as ')' makes low negative
                // we don't use it

                if (low < 0)
                    low = 0;
            }

            if (high < 0)
                return false;
        }

        if (low <= 0 && 0 <= high)
            return true;

        return false;
    }
};