class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& nums, int s, int k) {
        int i = 0, j = 0, ans = 0, csum = 0;
        while (j < nums.size()) {
            csum += nums[j][1];
            int c = 0;
            if (nums[i][0] >= s) {
                c = nums[j][0] - s;

            } else if (nums[j][0] <= s) {
                c = s - nums[i][0];
            } else
                c = min(2 * nums[j][0] - s - nums[i][0],
                        s - 2 * nums[i][0] + nums[j][0]);
            while (i <= j && c > k) {
                csum -= nums[i][1];
                i++;
                if(i==nums.size())break;
                if (nums[i][0] >= s) {
                    c = nums[j][0] - s;

                } else if (nums[j][0] <= s) {
                    c = s - nums[i][0];
                } else
                    c = min(2 * nums[j][0] - s - nums[i][0],
                            s - 2 * nums[i][0] + nums[j][0]);
            }
            ans = max(ans, csum);
            j++;
        }
        return ans;
    }

};