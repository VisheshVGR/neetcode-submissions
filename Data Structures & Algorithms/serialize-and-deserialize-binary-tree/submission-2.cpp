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

class Codec
{
    /*
    So I will be solving this question by serializing tree into
    inorder and preorder
    */
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string result;
        SerializeTree(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> tokens;
        string current;

        for (char ch : data)
        {
            if (ch == '#')
            {
                tokens.push_back(current);
                current.clear();
            }
            else
            {
                current.push_back(ch);
            }
        }

        int index = 0;
        return DeserializeTree(tokens, index);
    }

private:
    void SerializeTree(TreeNode *root, string &out)
    {
        if (!root)
        {
            out += "X#";
            return;
        }

        out += to_string(root->val);
        out += "#";
        SerializeTree(root->left, out);
        SerializeTree(root->right, out);
    }

    TreeNode *DeserializeTree(const vector<string> &tokens, int &index)
    {
        if (index >= (int)tokens.size())
            return nullptr;

        const string &token = tokens[index++];
        if (token == "X")
            return nullptr;

        TreeNode *node = new TreeNode(stoi(token));
        node->left = DeserializeTree(tokens, index);
        node->right = DeserializeTree(tokens, index);
        return node;
    }
};