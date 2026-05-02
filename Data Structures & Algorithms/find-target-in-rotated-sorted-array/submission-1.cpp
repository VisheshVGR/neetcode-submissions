
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size ();

        int i, j, m;
        i = 0; j = n - 1;
        
        while (i <= j)
        {
            m = i + ((j - i) >> 1);

            if (nums[m] == target)
                return m;
            
            // Find sorted side
            if (nums[i] <= nums[m])
            {
                // left is sorted
                // if target is in sorted side -> go left
                if (nums[i] <= target && target <= nums[m])
                    j = m - 1;
                else
                    i = m + 1;
            }
            else
            {
                // right is sorted
                if (nums[m] <= target && target <= nums[j])
                    i = m + 1;
                else
                    j = m - 1;
            }
        }

        return -1;
    }
};
