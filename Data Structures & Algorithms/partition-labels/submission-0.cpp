class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();

        // find start and end point of each char
        unordered_map<char, pair<int, int>> mp;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                // char not added
                mp[s[i]] = {i, i};
            }
            else
            {
                // char ending here
                mp[s[i]].second = i;
            }
        }

        // two array of start and end point
        // start[i]++ and end[i + 1]--
        vector<int> startpoint(n, 0);
        vector<int> endpoint(n, 0);

        for (auto &data : mp)
        {
            startpoint[data.second.first]++;
            endpoint[data.second.second]++;
        }

        // run iterator, if iterator == 0, we got a substring
        vector<int> ans;

        int str = 0;
        int end = 0;

        for (int i = 0; i < n; i++)
        {
            end += startpoint[i];

            end -= endpoint[i];

            if (end == 0)
            {
                ans.push_back(i - str + 1);

                str = i + 1;
            }
        }

        return ans;
    }
};