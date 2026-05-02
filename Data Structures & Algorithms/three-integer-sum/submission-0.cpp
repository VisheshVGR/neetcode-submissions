class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        sort nums to get distinct triplets
        select nums[i]
        then do two pointers on nums[i] and nums[j]

        nums[i] + nums[j] + nums[k] = 0;
        nums[j] + nums[k] = -num[i];
        */

        sort (nums.begin (), nums.end ());

        int n = nums.size ();

        int lasti = INT_MIN;

        int target;

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == lasti)
                continue;

            lasti = nums[i];

            target = -nums[i];

            // two pointer approach
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                // valid case
                if (nums[j] + nums[k] == target)
                {
                    ans.push_back ({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // move j 
                    while (j <= k && nums[j] == nums[j - 1])
                        j++;

                    // move k
                    while (k >= j && nums[k] == nums[k + 1])
                        k--;
                }
                else if (nums[j] + nums[k] < target)
                {
                    j++;

                    // move j 
                    while (j <= k && nums[j] == nums[j - 1])
                        j++;
                }
                else
                {
                    k--;

                    // move k
                    while (k >= j && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};
