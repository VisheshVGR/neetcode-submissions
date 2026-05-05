class PrefixTreeNode
{
public:
    bool wordendinghere;
    vector<PrefixTreeNode *> child;

    PrefixTreeNode()
    {
        wordendinghere = false;
        child.assign(26, nullptr);
    }
};

class PrefixTree
{
    PrefixTreeNode *root;

public:
    PrefixTree()
    {
        root = new PrefixTreeNode();
    }

    void insert(string word)
    {
        PrefixTreeNode *node = root;

        int n = word.size();

        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';

            if (node->child[idx] == nullptr)
                node->child[idx] = new PrefixTreeNode();

            node = node->child[idx];

            if (i == n - 1)
            {
                node->wordendinghere = true;
            }
        }
    }

    bool search(string word)
    {
        PrefixTreeNode *node = root;

        int n = word.size();

        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';

            if (node->child[idx] == nullptr)
                return false;

            node = node->child[idx];
        }

        if (node->wordendinghere == true)
            return true;

        return false;
    }

    bool startsWith(string prefix)
    {
        PrefixTreeNode *node = root;

        int n = prefix.size();

        for (int i = 0; i < n; i++)
        {
            int idx = prefix[i] - 'a';

            if (node->child[idx] == nullptr)
                return false;

            node = node->child[idx];
        }

        if (node->wordendinghere == true)
            return true;

        for (auto &child : node->child)
            if (child)
                return true;

        return false;
    }
};