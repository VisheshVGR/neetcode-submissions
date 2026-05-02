class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqs (127, 0), freqt (127, 0);

        for (auto &ch: s)
            freqs[ch]++;
        
        for (auto &ch: t)
            freqt[ch]++;

        for (int i = 0; i < 127; i++)
        {
            if (freqs[i] != freqt[i])
                return false;
        }

        return true;
    }
};
