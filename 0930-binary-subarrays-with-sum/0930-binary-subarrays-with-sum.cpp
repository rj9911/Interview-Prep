class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(), ans = 0, i = 0, j = 0, curr_sum = 0, consecZeros = 0;
        while(j < n){
            curr_sum += nums[j];
            if(curr_sum > goal)
                consecZeros = 0;
            while(i < j && curr_sum > goal)
                curr_sum -= nums[i++]; 
            while(i < j && nums[i] != 1){
                consecZeros++;
                i++;
            }
            if(curr_sum == goal)
                ans += consecZeros + 1;
            j++;
        }
        return ans;
    }

};