class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size ();

        int i, j, m;
        i = 0; j = n - 1;
        
        while (i <= j)
        {
            if (nums[i] <= nums[j])
                return nums[i];

            // If 2 elem left
            if (i + 1 == j)
                return nums[j];

            m = i + ((j - i) >> 1);
            
            // Find sorted side
            if (nums[i] <= nums[m])
            {
                // left is sorted
                // go right
                i = m;
            }
            else
            {
                // right is sorted
                // go left
                j = m;
            }
        }

        return -1;
    }
};