class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string pat) {
        if(pat.length() == 1) return w;
        vector<string> ans;
        for(auto x: w){
            map<char,char> re;
            set<char> s;
            int flag = 0;
            for(int i=0;i<x.length();i++){
                if(re.find(pat[i]) == re.end()){ 
                    if(s.find(x[i]) == s.end()){
                        re[pat[i]] = x[i];
                        s.insert(x[i]);
                    }else{
                        flag = 1; break;
                    }
                }
                else{
                    if(re[pat[i]] != x[i]){ flag =1; break;}
                }
            }
            if(!flag) ans.push_back(x);
        }
        return ans;
    }

};