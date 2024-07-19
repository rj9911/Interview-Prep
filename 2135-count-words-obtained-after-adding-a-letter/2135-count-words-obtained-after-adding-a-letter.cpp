class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& target) {
        int n = start.size();
        int m = target.size();
        unordered_map<string, int> mp;
        for(int i = 0; i<m; i++){
            sort(target[i].begin(), target[i].end());
            mp[target[i]]++;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            int arr[26] = {0};
            for(int j = 0; j<start[i].size(); j++){
                arr[start[i][j]-'a']++;
            }
            for(int j = 0; j<26; j++){
                string dum = start[i];
                if(arr[j]==0){
                    dum += 'a' + j;
                    sort(dum.begin(), dum.end());
                    if(mp.find(dum)!=mp.end()){
                        ans += mp[dum];
                        mp.erase(dum);
                    }
                }
            }
        }
        return ans;
    }
};