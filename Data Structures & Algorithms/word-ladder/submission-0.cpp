class Solution
{
    // Helper to check one char apart
    bool OneCharApart(string a, string b)
    {
        if (a.size() != b.size())
            return false;

        int cnt = 0;

        for (int i = 0; i < a.size(); i++)
            cnt += (a[i] != b[i]);

        return (cnt == 1) ? true : false;
    };

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        /*
        for each word we find what other words are at 1-char apart
        we create un-directed edge between them
        and give them a node value
        */

        int n = wordList.size();

        // Base case: If beginword is same as endword
        if (beginWord == endWord)
            return 0;

        // 2nd Case: If endword in not present in word list
        bool present = false;

        for (auto &str : wordList)
        {
            if (str == endWord)
                present = true;
        }

        if (present == false)
            return 0;

        // Create adjacency list
        vector<vector<int>> adjlst(n + 1, vector<int>());

        int nodevalue = 0;

        // string value, node value
        unordered_map<string, int> mp;

        mp[beginWord] = nodevalue;

        nodevalue++;

        // Building adj list
        // For 1st iteration
        for (auto &word : wordList)
        {
            mp[word] = nodevalue;

            nodevalue++;

            // Check if these are one char apart
            if (OneCharApart(word, beginWord))
            {
                adjlst[mp[word]].push_back(mp[beginWord]);
                adjlst[mp[beginWord]].push_back(mp[word]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Check if these are one char apart
                if (OneCharApart(wordList[i], wordList[j]))
                {
                    adjlst[mp[wordList[i]]].push_back(mp[wordList[j]]);
                    adjlst[mp[wordList[j]]].push_back(mp[wordList[i]]);
                }
            }
        }

        // Add all other nodes

        // Now we launch BFS from source (0) to see if we can reach target node
        int sourcenodevalue = mp[beginWord];
        int targetnodevalue = mp[endWord];

        vector<bool> visited(n + 1, false);

        queue<int> q;

        visited[sourcenodevalue] = true;
        q.push(sourcenodevalue);

        int distance = 1; // 1 is self word

        while (!q.empty())
        {
            int nodes = q.size();

            distance++; // for next word jump

            while (nodes--)
            {
                int currnode = q.front();
                q.pop();

                // check all adjacent nodes
                for (auto &nextnode : adjlst[currnode])
                {
                    // Target node found
                    if (nextnode == targetnodevalue)
                        return distance;

                    if (visited[nextnode])
                        continue;

                    visited[nextnode] = true;

                    q.push(nextnode);
                }
            }
        }

        return 0;
    }
};
