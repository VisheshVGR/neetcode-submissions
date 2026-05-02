class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size ();

        int i = 0, j = 0;
        int len = 0;

        vector<int> freq (255, 0);

        while (j < n)
        {
            freq[s[j]]++;

            while (freq[s[j]] > 1)
            {
                freq[s[i]]--;
                i++;
            }

            len = max (len, j - i + 1);
            j++;
        }

        return len;
    }
};
