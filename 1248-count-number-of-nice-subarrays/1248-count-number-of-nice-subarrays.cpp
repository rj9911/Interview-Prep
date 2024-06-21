class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        int oddCount = 0;  // Track the number of odd numbers encountered so far.

        for(int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                nums[i] = 1;
            } 
            else {
                nums[i] = 0;
            }
        }

        while (j < n) {
            if (nums[j] == 1) {
                count = 0;  // Reset count when encountering an odd number.
                oddCount++;
            }

            while (oddCount == k) {
                if (nums[i] == 1) {
                    oddCount--;  // Reduce oddCount when moving the left pointer.
                }
                i++;
                count++;
            }

            ans += count;  // Add the count to ans for all subarrays with k odd numbers.

            j++;
        }
        return ans;
    }

};