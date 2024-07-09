class Solution {
public:
    long long subarray_with_atmost_k(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        long long ans = 0;
        for(int i=0,j=0;j<nums.size();j++){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            ans += j-i+1; // basically the size of subarray;
        }
        return ans;
    }
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        for(auto it:nums)
            s.insert(it);
        int l = 1;
        int r = s.size();
        int ans;
        long long totalSub = 1LL*n*(n+1)/2;
        long long medianMin = (totalSub+1)/2;//min elements our value should be greater than or equal to
        while(l<=r){
            int mid = (r+l)>>1;
            if(subarray_with_atmost_k(nums,mid) >= medianMin){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }

};