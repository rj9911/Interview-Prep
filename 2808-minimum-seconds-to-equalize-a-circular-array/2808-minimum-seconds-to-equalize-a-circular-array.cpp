class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, int> pre, fir, ans;
        int n = size(nums);
        for(int i = 0; i<n; ++i)
        {
            if(pre.count(nums[i])) ans[nums[i]] = max(ans[nums[i]], (i-pre[nums[i]])/2);
            pre[nums[i]] = i;
            if(!fir.count(nums[i])) fir[nums[i]] = i;
        }
        int res = size(nums);
        for(auto it: pre)
        {
            ans[it.first] = max(ans[it.first] ,(n-it.second+fir[it.first])/2);
            res = min(res, ans[it.first]);
        }
        return res;
    }

};