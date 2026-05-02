class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        we will keep map or last elem and count of subsequence
        for each num
        if num-1 is present then we add num with freq = last freq + 1
        else we add num with freq = 1
        */
        sort (nums.begin (), nums.end ());

        // to break sequence in the end
        nums.push_back (INT_MIN);

        int n = nums.size ();

        // no elements were present
        if (n == 1)
            return 0;

        int longestseq = 1;
        int currseq = 1;
        int lastelem  = nums[0];

        for (int i = 1; i <= n; i++)
        {
            // skipping equal elems
            if (nums[i] == lastelem)
                continue;

            // if sequence is continuing
            if (nums[i] == lastelem + 1)
            {
                currseq++;
            }
            else
            {
                longestseq = max (longestseq, currseq);

                currseq = 1;
            }

            lastelem = nums[i];
        }

        return longestseq;
    }
};
