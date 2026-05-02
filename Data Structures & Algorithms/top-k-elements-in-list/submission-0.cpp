class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        num : freq map
        sort according to freq
        */
        int n = nums.size ();

        unordered_map<int, int> mp;

        for (auto &num: nums)
        {
            mp[num]++;
        }

        // freq, num
        vector<pair<int,int>> v;

        for (auto &data: mp)
            v.push_back ({data.second, data.first});

        // sorting according to frequency : decreasing order
        sort (v.begin (), v.end (), [](auto a, auto b){
            return a.first > b.first;
        });

        vector<int> ans;

        int i = 0;
        
        while (k--)
        {
            ans.push_back (v[i].second);

            i++;
        }

        return ans;
    }
};
