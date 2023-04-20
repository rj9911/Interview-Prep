class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto x : nums) mp[x]++;
        
        int mx=nums.size(),i=1;
        while(i<=mx){
            if(mp.find(i) == mp.end()) return i;
            else i++;
        }
        
        return mx+1;
    }
};