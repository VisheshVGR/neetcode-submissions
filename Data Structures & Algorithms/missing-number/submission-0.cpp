class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int hash = 0;

        int hash2 = 0;

        for (int i = 0; i <= n; i++) hash ^= i;

        for (int i = 0; i < n; i++) hash2 ^= nums[i];

        return (hash ^ hash2);
    }
};
