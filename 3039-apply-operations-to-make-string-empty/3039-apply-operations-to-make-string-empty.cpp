class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int> umap;
        for(char c:s){
            umap[c]++;
        }
        int maxi=INT_MIN;
        for(auto it:umap){
            maxi=max(maxi,it.second);
        }
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(umap[s[i]]==maxi){
                ans.push_back(s[i]);
                umap[s[i]]--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }

};