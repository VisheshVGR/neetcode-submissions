class MinSegTree
{
private:
    int n;
    int sz;
    vector<int> arr;

public:
    MinSegTree(int size)
    {
        n = size;
        sz = 4 * n;
        arr.assign(sz, INT_MAX);
    }

    void Add(int l, int r)
    {
        int val = r - l + 1;

        for (int i = l; i <= r; i++)
        {
            UpdateVal(i, val, 0, 0, n - 1);
        }
    }

    int Query(int i)
    {
        int val = FindVal(i, 0, 0, n - 1);

        return (val == INT_MAX) ? -1 : val;
    }

private:
    int UpdateVal(const int &idx_to_update, const int &val, int idx, int l, int r)
    {
        // We are at terminal node
        if (l == r)
        {
            // We came to update this node
            if (idx_to_update == l)
                return arr[idx] = min(arr[idx], val);
            // We are not updating this node
            else
                return arr[idx];
        }

        // If we don't fall in range
        if (idx_to_update < l || idx_to_update > r)
            return arr[idx];

        int m = l + (r - l) / 2;

        int left = UpdateVal(idx_to_update, val, (2 * idx) + 1, l, m);
        int right = UpdateVal(idx_to_update, val, (2 * idx) + 2, m + 1, r);

        return arr[idx] = min(left, right);
    }

    int FindVal(const int &idx_to_return, int idx, int l, int r)
    {
        // We are at terminal node
        if (l == r)
        {
            // We came to get value of this node
            if (idx_to_return == l)
                return arr[idx];
            // We are here for this node
            else
                return INT_MAX;
        }

        // If we don't fall in range
        if (idx_to_return < l || idx_to_return > r)
            return INT_MAX;

        int m = l + (r - l) / 2;

        int left = FindVal(idx_to_return, (2 * idx) + 1, l, m);
        int right = FindVal(idx_to_return, (2 * idx) + 2, m + 1, r);

        return min(left, right);
    }
};

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        MinSegTree tree(1005);

        for (auto &data : intervals)
        {
            tree.Add(data[0], data[1]);
        }

        vector<int> ans;

        for (auto &q : queries)
        {
            ans.push_back(tree.Query(q));
        }

        return ans;
    }
};