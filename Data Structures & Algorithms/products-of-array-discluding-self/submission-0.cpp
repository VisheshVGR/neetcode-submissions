class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Using prefix and suffix prod helper array
        nums will be operated using 1 based indexing
        */

        int n = nums.size ();

        vector<int> prefix (n+2);
        vector<int> suffix (n+2);

        // building prefix
        prefix[0] = 1;

        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];
        
        // building suffix
        suffix[n + 1] = 1;

        for (int i = n; i >= 1; i--)
            suffix[i] = suffix[i + 1] * nums[i - 1];        
        
        // building answer
        vector<int> answer;

        for (int i = 1; i <= n; i++)
        {
            answer.push_back (prefix[i - 1] * suffix[i + 1]);
        }

        return answer;
    }
};
