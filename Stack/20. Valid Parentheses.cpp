class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() && (s[i] == ']' || s[i] == '}' || s[i] == ')'))
                return false;
            else if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                char top = st.top();
                if (top == '[' && s[i] == ']')
                {
                    if (!st.empty())
                        st.pop();
                }
                else if (top == '(' && s[i] == ')')
                {
                    if (!st.empty())
                        st.pop();
                }
                else if (top == '{' && s[i] == '}')
                {
                    if (!st.empty())
                        st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (!st.empty())
            return false;

        return true;
    }
};