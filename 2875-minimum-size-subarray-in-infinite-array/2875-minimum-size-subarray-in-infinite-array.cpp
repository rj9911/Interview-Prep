class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        if(target == 0) return 0;
        int n = nums.size();
        
        long long sum = 0;
        for(auto num: nums)
            sum += num;
        
        int len = n*(target/sum);
        target = target%sum;
        if(target == 0)
            return len;
                
        int minLen = INT_MAX;
        int windowSum = 0;
        for(int start = 0, end = 0; end<2*n; end++){
            windowSum += nums[end%n];

            while(windowSum>target){
                windowSum -= nums[start%n];
                start++;
            }

            if(windowSum == target){
                minLen = min(minLen, end-start+1);
            }
        }
        
        return minLen == INT_MAX? -1: len+minLen;   
    }

};