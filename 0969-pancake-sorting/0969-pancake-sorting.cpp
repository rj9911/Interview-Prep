class Solution {
public:
    vector<int> pancakeSort(vector<int>& nums) {
        int n = nums.size();
        int j =n-1;
        vector<int> res;
        while(j>=0){
            priority_queue<pair<int,int>> pq;
            for(int i=j;i>=0;i--){
                pq.push({nums[i],i});
            }
            auto it = pq.top();
            if(it.second !=j ){
                reverse(nums.begin(),nums.begin()+(it.second+1));
                res.push_back(it.second+1);
                reverse(nums.begin(),nums.begin()+j+1);
                res.push_back(j+1);
            }
            j--;
        }
        return res;
    }

};