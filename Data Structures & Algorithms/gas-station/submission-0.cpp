class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        // Making 2*N size arr
        vector<int> arr;

        for (int i = 0; i < 2 * n; i++)
        {
            arr.push_back(gas[i % n] - cost[i % n]);
        }

        // now we use sliding window to find max positive window
        // and if size of positive window == n
        // we return starting index

        int l = 0;
        int r = 0;

        int currsum = 0;

        while (r < 2 * n)
        {
            // add elem
            currsum += arr[r];

            // increment r to add next elem
            r++;

            // if invalid window
            // remove elem
            while (currsum < 0)
            {
                currsum -= arr[l];
                l++;
            }

            // check if valid window
            if (currsum >= 0 && (r - l) == n)
            {
                return l;
            }
        }

        return -1;
    }
};