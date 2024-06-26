class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        int ans = 0;
        // Storing positions for every element //
        for(int idx=0; idx<n; idx++){
            mpp[nums[idx]].push_back(idx);
        }
        // Trying every element //
        for(auto &p : mpp){
            auto &ele = p.first;
            auto &indices = p.second;
            int len = indices.size();
            int left = 0;
            // Sliding Window on Indicies of a element //
            for(int right=0; right<len; right++){
                int total = indices[right] - indices[left] + 1;
                int same = right - left + 1;
                int diff = total - same;
                while( diff > k ){
                    left += 1;
                    total = indices[right] - indices[left] + 1;
                    same = right - left + 1;
                    diff = total - same;
                }
                ans = max(ans, same);
            }
        }
        return ans;
    }

};