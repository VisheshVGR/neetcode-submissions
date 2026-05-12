class MinStack
{
    // value, min
    stack<pair<int, int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int mn;

        if (st.empty())
            mn = val;
        else
            mn = min(val, st.top().second);

        st.push({val, mn});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};