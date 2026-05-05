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

class WordDictionary
{
    PrefixTreeNode *root;

public:
    WordDictionary()
    {
        root = new PrefixTreeNode();
    }

    void addWord(string word)
    {
        PrefixTreeNode *node = root;

        int n = word.size();

        for (int i = 0; i < n; i++)
        {
            int idx = word[i] - 'a';

            if (node->child[idx] == nullptr)
                node->child[idx] = new PrefixTreeNode();

            node = node->child[idx];
        }

        node->wordendinghere = true;
    }

    bool search(string word)
    {
        int n = word.size();

        PrefixTreeNode *node = root;

        if (searchHelper(word, n, 0, node))
            return true;

        return false;
    }

private:
    bool searchHelper(const string &word, const int &n, int idx, PrefixTreeNode *node)
    {
        // Is this a wild char
        if (word[idx] == '.')
        {
            for (auto &child : node->child)
            {
                if (!child)
                    continue;

                // we found a node with char

                // Is this last char
                if (idx == n - 1)
                {
                    // IF yes and word ends here
                    if (child->wordendinghere)
                        return true;

                    // We check for other char, if word ends there
                }
                else if (searchHelper(word, n, idx + 1, child))
                {
                    // we try finding deeper
                    return true;
                }
            }

            return false;
        }

        int charidx = word[idx] - 'a';

        if (node->child[charidx] == nullptr)
            return false;

        // Char found

        // Is this last char?
        if (idx == n - 1)
        {
            if (node->child[charidx]->wordendinghere)
                return true;
            else
                return false;
        }

        // No? Keep searching next char
        return searchHelper(word, n, idx + 1, node->child[charidx]);
    }
};