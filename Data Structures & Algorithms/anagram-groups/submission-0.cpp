class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size ();

        map<vector<int>, vector<string>> mp;

        vector<int> freq (26, 0);

        for (int i = 0; i < n; i++)
        {
            string &currstring = strs[i];

            freq.assign (26, 0);

            for (auto &ch: currstring)
            {
                freq[ch - 'a']++;
            }

            mp[freq].push_back (currstring);
        }

        vector<vector<string>> ans;

        for (auto &data: mp)
        {
            ans.push_back (data.second);
        }

        return ans;
    }
};
