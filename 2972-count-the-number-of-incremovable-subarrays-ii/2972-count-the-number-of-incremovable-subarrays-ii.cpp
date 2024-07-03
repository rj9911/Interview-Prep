class Solution {
public:
    #define ll long long int

    long long incremovableSubarrayCount(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n = nums.size();
        int leftIdx = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] < nums[i]) leftIdx++;
            else break;
        }
        if(leftIdx == n-1) {
            ll ans = (n * (n+1)) / 2;
            return ans;
        }
        ll rightIdx = n-1;
        for(int i = n-1; i > 0; i--) {
            if(nums[i-1] < nums[i]) rightIdx--;
            else break;
        }
        ll totalIncremovableSubarrays = 0;
        totalIncremovableSubarrays += (n - rightIdx ) + 1;
        int l = 0 , r = rightIdx;
        while(l <= leftIdx) {
            while(r < n && nums[l] >= nums[r]) r++;
            totalIncremovableSubarrays += (n-r+1);
            l++;
        }
        return totalIncremovableSubarrays;
    }

};