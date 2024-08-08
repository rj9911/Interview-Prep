class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        long long mp[nums.size()];
        memset(mp, 0, sizeof(mp));
        long long ans=0;
        int j=0;

        sort(nums.begin(), nums.end());
        for(int i=0; i<req.size(); i++)
        {
            ++mp[req[i][0]];
            if(req[i][1]<nums.size()-1) --mp[req[i][1]+1];
        }

        for(int i=1; i<nums.size(); i++) mp[i] = mp[i] + mp[i-1];

        sort(mp, mp+nums.size());
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(mp[i]==0) break;
            ans = ans + mp[i]*nums[i];
            ans = ans%(long long)(1e9+7);
        }


        return ans;
    }

};