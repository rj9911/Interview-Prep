class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<pair<int,int>> ranges;

        int start = INT_MAX, end = INT_MIN;
        // store all possible range in ranges
        for(auto num: nums){
            int left = num-k, right = num+k;
            ranges.push_back({left,right});
            start = min(start,left);
            end = max(end,right);
        }
        // Now question modifies to calculate maximum no. of overlapping intervals.

        unordered_map<int,int> mp;
        for(auto num: ranges){
            int first = num.first, second = num.second;
            mp[first]++;
            mp[second+1]--;
        }
        // Now calculating the answer
        int ans = 0, temp=0;
        for(int it = start; it<=end+1; it++){
            temp += mp[it];
            ans = max(ans,temp);
        }
        return ans;
    }

};