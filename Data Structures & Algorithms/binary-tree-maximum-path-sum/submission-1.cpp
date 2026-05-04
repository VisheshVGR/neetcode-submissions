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
    int mx;

public:
    int maxPathSum(TreeNode *root)
    {
        /*
        at every node

        max path can be: root / root + root.left /root + root.right / root + root.left + root.right

        return max (root + root.left, root + root.right)

        */

        mx = INT_MIN / 4;

        helper(root);

        return mx;
    }

private:
    int helper(TreeNode *root)
    {
        if (!root)
            return INT_MIN / 4;

        int left = helper(root->left);
        int right = helper(root->right);

        mx = max(
            mx,
            max(
                root->val,
                max(
                    root->val + left + right,
                    max(
                        root->val + left,
                        root->val + right))));

        return max(
            root->val,
            max(
                root->val + left,
                root->val + right));
    }
};