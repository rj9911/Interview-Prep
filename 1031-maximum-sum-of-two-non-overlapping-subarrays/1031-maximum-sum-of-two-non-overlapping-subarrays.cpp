class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int result = -1e9;
        
        //prefix sum:
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] += prefix[i-1] + nums[i];
        }
        
        //fix one subArray and move another:
        for(int i=0;i<n;i++){
            int start1 = i, end1 = i+firstLen-1;
            if(end1 > n-1) break;
            
            //sum of first subArray:
            int firstSubArraySum = prefix[end1];
            if(start1 > 0) firstSubArraySum -= prefix[start1 - 1];
            
            for(int j=0;j<n;j++){
                int start2 = j, end2 = j+secondLen-1;
                if(end2 > n-1) break;
                            
                // check for non overlapping:
                if(end2 < start1 or start2 > end1){
                    //sum of second SubArray:
                    int secondSubArraySum = prefix[end2];
                    if(start2 > 0) secondSubArraySum -= prefix[start2 - 1];
                    result = max(result, (firstSubArraySum + secondSubArraySum));
                }   
            }
        }
        
        return result;
    }

};