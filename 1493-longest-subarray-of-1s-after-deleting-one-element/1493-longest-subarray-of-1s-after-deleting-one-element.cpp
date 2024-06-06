class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_count = 0;
        int i = 0;
        int temp_count = 0;
        int last = -1;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                max_count = std::max(max_count, temp_count);
                temp_count = i - last - 1;
                last = i;
            } else {
                temp_count++;
            }
            i++;
        }

        max_count = std::max(max_count, temp_count);
        return (last == -1) ? nums.size() - 1 : max_count;
    }

};