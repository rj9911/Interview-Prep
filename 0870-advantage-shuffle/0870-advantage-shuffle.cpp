class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        priority_queue<pair<int, int>> q;
        int n = nums1.size();
          vector<int>ans(n);
        for(int i = 0; i < nums2.size(); i++){
            q.push({nums2[i], i});// larger elements in the top of the queue 
        }
          int small = 0;// pointer for inserting small elements in the nums1 array 
        int big =  n - 1; // pointer for inserting larger elemtn in the nums1 array 
        while (!q.empty()){
            auto top = q.top();
            q.pop();
            if(nums1[big] > top.first){
                ans[top.second] = nums1[big];
                big--;
            }else{
                ans[top.second] = nums1[small];
                small++;
            }
        }
        return ans;
    }

};