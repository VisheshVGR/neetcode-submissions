class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        char top;

        for (auto &ch: s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push (ch);
            }   
            else
            {
                if (st.empty ())
                    return false;

                top = st.top ();

                if (
                    (ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')
                )
                {
                    st.pop ();
                }
                else
                {
                    return false;
                }
            }
        }

        if (st.empty ())
            return true;
        
        return false;
    }
};
