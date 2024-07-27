class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n=words.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].length();j++){
                mp[words[i][j]]++;
            }
        }
        vector<int> use(n,0);
        for(int i=0;i<n;i++){
            use[i]=words[i].length();
        }
        int ans=0;
        sort(use.begin(),use.end());
        int use2=0;
        for(auto a:mp){
            if(a.second>=2){
                use2+=a.second/2;
            }
        }
        for(int i=0;i<n;i++){
            if(use[i]/2<=use2){
                use2-=use[i]/2;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }

};