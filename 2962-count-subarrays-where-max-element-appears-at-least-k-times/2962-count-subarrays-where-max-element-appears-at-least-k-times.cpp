class Solution {
public:
    long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int max_val = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
        }
        
        int start = 0, end = 0, mef = 0;
        long count = 0;
        
        while (end < n) {
            if (nums[end] == max_val) {
                mef++;
            }
            
            while (mef >= k) {
                count += n - end;
                if (nums[start] == max_val) {
                    mef--;
                }
                start++;
            }
            
            end++;
        }
        
        return count;
    }


};