class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int result = 0;
        st.push(-1);
        for(int i = 0; i<s.size(); i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else if(s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if(!st.empty())
                {
                    st.pop();
                    if(st.empty())
                    {
                        st.push(i);
                    }
                    else
                    {
                        int value = i - st.top();
                        if(value > result)
                        {
                            result = value;
                        }
                    }
  
                }
                else
                {
                    st.push(i);
                }
            }
        }
        return result;
    }
};