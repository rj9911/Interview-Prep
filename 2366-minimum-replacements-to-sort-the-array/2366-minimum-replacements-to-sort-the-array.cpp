class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0, n = nums.size(), last = nums[n - 1];
        for(int i=n-2; i>=0; i--) {
            if(nums[i] > last) {
                ans += ceil((double)nums[i] / last) - 1;
                if(nums[i] % last) {
                    last = nums[i] / ceil((double)nums[i] / last);
                } 
            }
            else last = nums[i];
        }
        return ans;
    }

};