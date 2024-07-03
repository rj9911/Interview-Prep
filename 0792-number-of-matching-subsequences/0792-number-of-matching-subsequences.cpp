class Solution {
public:
int numMatchingSubseq(string s, vector<string>& words) {
        vector<string> mp[128];
        for(auto str : words)
            mp[str[0]].push_back(str);
        int ans = 0;
        unordered_set<string>subS;
        for(int i=0; i<s.size(); i++){
            auto v = mp[s[i]];
            mp[s[i]].clear();
            for(auto word : v){
                if(word.size() == 1)
                    ans++;
                else
                    mp[word[1]].push_back(word.substr(1));
            }
        }
        return ans;
    }

};