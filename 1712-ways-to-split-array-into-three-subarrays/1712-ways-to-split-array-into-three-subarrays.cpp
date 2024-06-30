class Solution {
public:
    int waysToSplit(vector<int>& nums) {        
        int n = nums.size();
        for(int i=1;i<n;i++)nums[i]+=nums[i-1];        
        int left  = 0; 
        int mid = 1;    
        int right = 2;  
        int count = 0;
        while(left < n-2)
        {
            mid = max(mid,left+1);
            while(mid<n-1 && nums[mid]<2*nums[left])mid++;            
            right = max(mid,right);
            while(right<n-1 && nums[right]-nums[left]<=nums[n-1]-nums[right])right++;            
            count = (count + right - mid) % 1000000007;            
            left++;
        }       
        return count;
    }

};