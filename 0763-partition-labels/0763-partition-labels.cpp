class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        int n = s.size();
        int last_occ = INT_MIN;
        unordered_map<int,pair<int,int>>mp;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = {i,i};
            }else{
                mp[s[i]].second = i;
            }
        }
        last_occ = mp[s[0]].second;
        int size = mp[s[0]].second - mp[s[0]].first+1;
        ans.push_back(size);
        for(int i = 1;i<n;i++){
            if(i<=last_occ){
                if(mp[s[i]].second>last_occ){
                    size+=(mp[s[i]].second-last_occ);
                    last_occ = mp[s[i]].second;
                    ans.pop_back();
                    ans.push_back(size);
                }
            }else{
                last_occ = mp[s[i]].second;
                size = mp[s[i]].second - mp[s[i]].first+1;
                ans.push_back(size);
            }
        }
        return ans;
    }

};