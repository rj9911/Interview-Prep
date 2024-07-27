class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<word.size();i+=k){
            string ans;
            for(int j=i;j<i+k;j++){
                ans+=word[j];
            }
            mp[ans]++;
        }
        string check;
        int c=0;
        for(auto it:mp){
            if(it.second>c) {
                c=it.second;
                check=it.first;
            }
        }
        
        int cnt=0;
          for(int i=0;i<word.size();i+=k){
            string ans;
            for(int j=i;j<i+k;j++){
                ans+=word[j];
            }
            if(ans!=check) cnt++;
        }
        return cnt;
    }

};