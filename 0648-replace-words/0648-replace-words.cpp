class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        unordered_set<string> st(d.begin(),d.end());
        string ans="";
        for(int i=0;i<s.size();i++){
            string temp="";
            bool flag=true;
            while(i<s.size() && s[i]!=' '){
                temp+=s[i];
                if(st.count(temp)) {
                    flag =false;
                    ans+=temp,ans+=' ';
                    while(i<s.size() && s[i]!=' ') i++;
                }
                if(flag && (s[i+1]==' ' || i+1==s.size())) ans+=temp,ans+=' ';
                if(s[i]!=' ') i++;
            }
        }
        ans.pop_back();
        return ans;
    }

};