class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();

        stack<int> st;

        int num1;
        int num2;

        for (auto &str : tokens)
        {
            if (str == "+")
            {
                num1 = st.top();
                st.pop();

                num2 = st.top();
                st.pop();

                st.push(num2 + num1);
            }
            else if (str == "-")
            {
                num1 = st.top();
                st.pop();

                num2 = st.top();
                st.pop();

                st.push(num2 - num1);
            }
            else if (str == "*")
            {
                num1 = st.top();
                st.pop();

                num2 = st.top();
                st.pop();

                st.push(num2 * num1);
            }
            else if (str == "/")
            {
                num1 = st.top();
                st.pop();

                num2 = st.top();
                st.pop();

                st.push(num2 / num1);
            }
            else
            {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};