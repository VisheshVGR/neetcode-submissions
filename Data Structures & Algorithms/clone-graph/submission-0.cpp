/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    // Old node -> new node
    unordered_map<Node *, Node *> mp;

    // new node -> processed / not processed
    unordered_map<Node *, bool> processed;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;

        return cloneNodeHelper(node);
    }

private:
    Node *cloneNodeHelper(Node *oldnode)
    {
        Node *newnode;

        if (mp[oldnode])
        {
            newnode = mp[oldnode];
        }
        else
        {
            newnode = new Node(oldnode->val);

            mp[oldnode] = newnode;
        }

        // If already processed
        if (processed[newnode])
            return newnode;

        // processed this node
        processed[newnode] = true;

        // Fill childrens
        for (auto &childnode : oldnode->neighbors)
        {
            newnode->neighbors.push_back(cloneNodeHelper(childnode));
        }

        return newnode;
    }
};
