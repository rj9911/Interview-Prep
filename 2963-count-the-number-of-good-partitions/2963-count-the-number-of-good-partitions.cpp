class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7, cnt_grps = 0, j = 0;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++)
            mp[nums[i]] = i;
        while(j < n){
            int maxi = mp[nums[j]];
            for(int i = j + 1 ; i < maxi ; i++)
                maxi = max(maxi, mp[nums[i]]);
            j = ++maxi;
            cnt_grps++;
        }
        int ans = 1;
        for(int i = 0 ; i < cnt_grps - 1 ; i++)
            ans = (ans * 2) % mod;
        return ans;
    }

};