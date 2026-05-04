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

class Solution {
    vector<int> v;
public:
    int kthSmallest(TreeNode* root, int k) {
        /*
        BST inorder is in sorted order
        so we save inorder in array and then find k-th elem
        */

        inorder (root);

        return v[k - 1];
    }
private:
    void inorder (TreeNode *root)
    {
        if (!root)
            return;

        inorder (root->left);

        v.push_back (root->val);

        inorder (root->right);
    }
};
