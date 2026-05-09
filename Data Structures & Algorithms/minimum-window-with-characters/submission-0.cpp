class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();

        vector<int> current_freq(128, 0);
        vector<int> required_freq(128, 0);

        for (auto &ch : t)
        {
            required_freq[ch]++;
        }

        int r = 0; // points at idx which has to be added
        int l = 0; // points at idx which has to be removed

        int mnwindowsize = INT_MAX;
        int mnwindowstart = 0;

        while (r < n)
        {
            // add char until window is not valid
            while (r < n && windowIsValid(current_freq, required_freq) == false)
            {
                current_freq[s[r]]++;

                r++;
            }

            // we have a valid window

            // remove char until window is valid
            while (l < r && windowIsValid(current_freq, required_freq) == true)
            {
                if (r - l < mnwindowsize)
                {
                    mnwindowstart = l;
                    mnwindowsize = r - l;
                }

                current_freq[s[l]]--;

                l++;
            }
        }

        if (mnwindowsize == INT_MAX)
            mnwindowsize = 0;

        return s.substr(mnwindowstart, mnwindowsize);
    }

private:
    bool windowIsValid(const vector<int> &curr, const vector<int> &req)
    {
        for (int i = 0; i < 128; i++)
        {
            if (curr[i] < req[i])
                return false;
        }

        return true;
    }
};
