class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int maxLength = -1, currSum = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while (left <= right && currSum > totalSum - x){
                currSum -= nums[left];
                left++;
            }
                
            if (currSum == totalSum - x){
                maxLength = max(maxLength, right - left + 1);
            }
        }
        
        if(maxLength == -1){
            return -1;
        }
        else{
            return nums.size() - maxLength;
        }
    }

};