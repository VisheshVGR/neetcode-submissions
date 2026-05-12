class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();

        // val, idx
        stack<pair<int, int>> st;

        vector<int> ans;

        for (int i = n - 1; i >= 0; i--)
        {
            int val = temperatures[i];

            // Remove elems which are small than curr elem
            while (!st.empty() && val >= st.top().first)
            {
                st.pop();
            }

            // stack top will be next greate elem
            if (st.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(st.top().second - i);
            }

            // Add curr elem
            st.push({val, i});
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};