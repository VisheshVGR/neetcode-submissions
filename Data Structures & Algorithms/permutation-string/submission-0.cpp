class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> required_freq(26, 0);

        for (auto &ch : s1)
        {
            required_freq[ch - 'a']++;
        }

        vector<int> current_freq(26, 0);

        for (int i = 0; i < n; i++)
        {
            current_freq[s2[i] - 'a']++;
        }

        if (IsSame(current_freq, required_freq))
            return true;

        for (int i = n; i < m; i++)
        {
            // add char
            current_freq[s2[i] - 'a']++;

            // remove char
            current_freq[s2[i - n] - 'a']--;

            if (IsSame(current_freq, required_freq))
                return true;
        }

        return false;
    }

private:
    bool IsSame(const vector<int> &f1, const vector<int> &f2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (f1[i] != f2[i])
                return false;
        }

        return true;
    }
};