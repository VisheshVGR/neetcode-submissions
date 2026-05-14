class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();

        // Base case
        if ((n % groupSize) != 0)
            return false;

        map<int, int> mp;

        for (auto &val : hand)
            mp[val]++;

        int lastval;
        int currgroupsize = 0;

        while (mp.empty() == false)
        {
            if (currgroupsize == 0)
            {
                currgroupsize = groupSize;
                lastval = -1;
            }

            if (lastval == -1)
            {
                // select first elem
                lastval = mp.begin()->first;

                mp[lastval]--;

                if (mp[lastval] == 0)
                    mp.erase(lastval);
            }
            else
            {
                // Incremented key not found
                if (mp[lastval + 1] == 0)
                    return false;

                mp[lastval + 1]--;

                if (mp[lastval + 1] == 0)
                    mp.erase(lastval + 1);

                lastval = lastval + 1;
            }

            currgroupsize--;
        }

        return true;
    }
};
