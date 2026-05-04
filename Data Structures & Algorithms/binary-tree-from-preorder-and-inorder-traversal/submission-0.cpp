/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();

        int l = 0;
        int r = n - 1;
        int m;

        // Guaranteed to have at least 1 node which will be our root node accordint to pre-order
        TreeNode *root = new TreeNode(preorder[0]);

        m = findIdx(preorder[0], inorder, l, r);

        root->left = buildTreeHelper(preorder, inorder, 1, l, m - 1);
        root->right = buildTreeHelper(preorder, inorder, 1, m + 1, r);

        return root;
    }

private:
    int findIdx(int val, vector<int> &inorder, int l, int r)
    {
        for (int i = l; i <= r; i++)
        {
            if (inorder[i] == val)
                return i;
        }

        return -1;
    }

    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int rootidx, int l, int r)
    {
        // Base case
        if (l > r)
            return nullptr;

        int m;

        // Find root index
        while (true)
        {
            m = findIdx(preorder[rootidx], inorder, l, r);

            if (m != -1)
                break;

            rootidx++;
        }

        // We found rootidx
        TreeNode *root = new TreeNode(preorder[rootidx]);

        root->left = buildTreeHelper(preorder, inorder, rootidx + 1, l, m - 1);
        root->right = buildTreeHelper(preorder, inorder, rootidx + 1, m + 1, r);

        return root;
    }
};