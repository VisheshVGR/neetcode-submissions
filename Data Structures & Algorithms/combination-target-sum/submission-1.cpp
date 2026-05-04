class Solution
{
    vector<vector<int>> ans;

    int n;

public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        // so that if adding current elem more time breaks result
        // we know for sure we can't go forward

        n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> arr;

        helper(nums, target, 0, arr, 0);

        return ans;
    }

private:
    void helper(vector<int> &nums, const int &target, int idx, vector<int> &arr, int currsum)
    {
        if (currsum == target)
        {
            // Possible solution found
            ans.push_back(arr);
            return;
        }

        if (idx == n)
        {
            // no more elem left
            return;
        }

        // if adding elem is not possible
        if (currsum + nums[idx] > target)
        {
            // Going forward we have elem with more value hence we break

            return;
        }

        // add elem

        arr.push_back(nums[idx]);

        helper(nums, target, idx, arr, currsum + nums[idx]);

        // dont add elem
        arr.pop_back ();
        
        helper(nums, target, idx + 1, arr, currsum);

    }
};