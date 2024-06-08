class Solution {
public:
    int minimumTime(string s) {
        if(s.size()==1){
            if(s[0]=='1') return 1;
            else return 0;
        }
        int re = INT_MAX,n=s.size();
        
        vector<int> nums; 
        for(int i = 0; i<s.size();++i) if(s[i]=='1') nums.push_back(i);
        if(nums.size()==0) return 0;
        
        vector<int> left(nums.size(),INT_MAX),right(nums.size(),INT_MAX);
        left[0] = min(2,nums[0]+1);
        for(int i = 1; i<nums.size();++i) 
            left[i] = min(left[i-1]+2,nums[i]+1);
        
        right[nums.size()-1] = min(n-nums[nums.size()-1],2);
        for(int i = nums.size()-2; i>=0;--i)
            right[i] = min(right[i+1]+2,n-nums[i]);
        
        re = min(right[0],left[left.size()-1]);
        for(int i = 1; i<nums.size();++i) re = min(left[i-1]+right[i],re);
        
        return re;
    }

};