class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indDiff, int valueDiff) {
        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mpq;
        for(auto i = 0; i < nums.size(); ++i) { pq.push({nums[i], i}); mpq.push({nums[i], i}); }
        for(int i = 0; i + indDiff < nums.size(); ++i){
            while(pq.size() && pq.top().second < i+indDiff) pq.pop();
            while(mpq.size() && mpq.top().second < i+indDiff) mpq.pop();
            if(pq.size() && abs(nums[i] - pq.top().first) >= valueDiff ) return {i, pq.top().second};
            if(mpq.size() && abs(nums[i] - mpq.top().first) >= valueDiff ) return {i, mpq.top().second};
        }
        
        return {-1,-1};
    }

};