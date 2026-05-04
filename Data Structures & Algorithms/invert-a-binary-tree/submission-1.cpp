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
    TreeNode *invertTree(TreeNode *root)
    {
        /*
        For every level we store NULL(INT_MIN) or node itself
        and we build accordingly
        */
        if (!root)
            return root;

        vector<vector<TreeNode *>> arr;
        vector<TreeNode *> levelarr;

        // Fill into arr
        queue<TreeNode *> q;

        // INIT
        q.push(root);

        while (!q.empty())
        {
            int nodes = q.size();

            levelarr.clear();

            while (nodes--)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    levelarr.push_back(node->left);
                    q.push(node->left);
                }
                else
                {
                    levelarr.push_back(nullptr);
                }

                if (node->right)
                {
                    levelarr.push_back(node->right);
                    q.push(node->right);
                }
                else
                {
                    levelarr.push_back(nullptr);
                }
            }

            reverse(levelarr.begin(), levelarr.end());

            arr.push_back(levelarr);
        }

        // Build reverse list
        q.push(root);

        for (int i = 0; i < arr.size(); i++)
        {
            int j = 0;

            while (j < arr[i].size())
            {
                TreeNode *node = q.front();
                q.pop();

                node->left = arr[i][j];
                node->right = arr[i][j + 1];

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                j += 2;
            }
        }

        return root;
    }
};