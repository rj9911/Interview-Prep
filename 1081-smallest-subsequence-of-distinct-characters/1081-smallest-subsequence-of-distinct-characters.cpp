class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>last;
        unordered_map<char,bool>taken;
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++)
            last[s[i]]=i;
        for(int i=0;i<s.size();i++)
        {
            if(taken.find(s[i])!=taken.end())
                continue;
            while(st.size()!=0 && s[i]<st.top() && last[st.top()]>i)
            {
                taken.erase(st.top());
                st.pop();
            }
            taken[s[i]]=true;
            st.push(s[i]);
        }
        while(st.size()>0)
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;        
    }

};