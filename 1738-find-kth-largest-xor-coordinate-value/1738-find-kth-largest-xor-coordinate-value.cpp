class Solution {
public:
    int kthLargestValue(vector<vector<int>>& nums, int k) {
        int m=nums.size(),n=nums[0].size();
        vector<vector<int>>top=nums;
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                top[i][j]^=top[i-1][j];
            }
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums[i][j]=top[i][j];
                if(j)
                    nums[i][j]^=nums[i][j-1];
                int curr=nums[i][j];
                if(pq.size()==k){
                    if(pq.top()<curr){
                        pq.pop();
                        pq.push(curr);
                    }
                }else{
                    pq.push(curr);
                }
            }
        }
        return pq.top();
    }

};