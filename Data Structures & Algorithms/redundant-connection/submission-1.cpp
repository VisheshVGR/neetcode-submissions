class DSU
{
private:
    vector<int> parent;

public:
    DSU(int n)
    {
        // Everyone is their own parent
        // 1-based indexing
        parent.assign(n + 1, -1);
    }

    bool Join(int a, int b)
    {
        // a != b
        int para = FindParent(a);
        int parb = FindParent(b);

        if (para == parb)
            return false;

        // b latching to a
        parent[parb] = para;

        return true;
    }

private:
    int FindParent(int a)
    {
        if (parent[a] == -1)
            return a;

        return parent[a] = FindParent(parent[a]);
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &z)
    {
        /*
        We keep adding nodes
        one node will make a cycle
        we have to return that node

        we can use DSU to find that node
        */

        int n = z.size();

        DSU dsu(n);

        for (auto &data : z)
        {
            if (dsu.Join(data[0], data[1]) == false)
            {
                return {data[0], data[1]};
            }
        }

        return {-1, -1};
    }
};