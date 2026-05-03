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
    bool issubtree;
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        issubtree = false;

        helper (root, subRoot);

        return issubtree;
    }
private:
    void helper (TreeNode *p, TreeNode *q)
    {
        if (!p)
            return;

        if (isSameTree (p, q))
            issubtree = true;

        helper (p->right, q);
        helper (p->left, q);
        
    }

private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && !q)
            return false;

        if (!p && q)
            return false;

        if (!p && !q)
            return true;

        if (p->val != q->val)
            return false;

        return isSameTree (p->left, q->left) && isSameTree (p->right, q->right);
    }
};
