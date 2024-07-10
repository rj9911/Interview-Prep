class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        ans = min(ans, abs(k - nums[0]));
        if(n == 1) return ans;

        int l = 0, r = 1;
        int curr_l_val = nums[l];

        while(r < n) {
            int curr_val = curr_l_val | nums[r];

            if(abs(k - curr_val) <= ans) ans = abs(k - curr_val);
            if(ans == 0) return 0;

            if(curr_val < k) {
                r++;
                curr_l_val = curr_val;
            }
            else {
                l++;
                curr_l_val = 0;
                if(l == r) r++;

                for(int i = l; i < r; i++) {
                    curr_l_val |= nums[i];
                }
            }

            ans = min(ans, abs(k - curr_l_val));
        }

        return ans;
    }




};