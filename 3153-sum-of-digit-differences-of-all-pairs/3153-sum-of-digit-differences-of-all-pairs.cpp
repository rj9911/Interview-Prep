class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long cnt=0;
        long long l=to_string(nums[0]).size();
        vector<unordered_map<char, long long>>mp(l);
        for(auto it: nums){
            string s=to_string(it);
            for(int i=0; i<s.size(); i++){
                mp[i][s[i]]++;
            }
        }
        for(int i=0; i<l; i++){
            for(auto it: mp[i]){
                for(auto it1: mp[i]){
                    if(it.first!=it1.first){
                        cnt+=(it.second*it1.second);
                    }
                }
            }
        }
        return cnt/2;
    }

};