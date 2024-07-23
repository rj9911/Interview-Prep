class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            unordered_set<int>st;
            int currcount=0;
            for(int j=i; j<n; j++){
                if(!st.count(nums[j])){
                    if(st.count(nums[j]+1) && st.count(nums[j]-1)){
                        currcount--;
                    }
                    else if(!st.empty() && !st.count(nums[j]-1) && !st.count(nums[j]+1)){
                        currcount++;
                    }
                }
                st.insert(nums[j]);
                count+= currcount;
                
            }
        }
        return count;
        
    }
};