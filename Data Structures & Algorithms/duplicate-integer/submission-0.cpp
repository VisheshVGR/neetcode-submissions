class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto &num: nums)
        {
            if (mp[num] != 0)
                return true;

            mp[num]++;
        }

        return false;
    }
};