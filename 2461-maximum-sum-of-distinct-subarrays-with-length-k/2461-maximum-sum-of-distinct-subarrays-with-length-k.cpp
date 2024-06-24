class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long int ans = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i])==0){//get sum of each window unique element
                sum += nums[i];
            }
            mp[nums[i]]++;
            if(mp.size()==k){//if in map all element are unique than get maximum ans
                ans = max(ans,sum);
            }
            if(i-k+1>=0){
                mp[nums[i+1-k]]--;
                if(mp[nums[i+1-k]]==0){
                    sum -= nums[i+1-k];
                    mp.erase(nums[i+1-k]);
                }
            }
        }
        return ans;
    }

};