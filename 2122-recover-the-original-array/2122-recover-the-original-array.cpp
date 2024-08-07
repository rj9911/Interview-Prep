class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp, mpp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            mpp[nums[i]]++;
        }
        for(int i = 1; i < n; i++) {
            bool ok = true;
            int k = (nums[i]-nums[0])/2;
            if(k == 0) continue;
            vector<int> res;
            for(int j = 0; j < n; j++) {
                if(mpp[nums[j]] == 0) continue;
                if(mpp[nums[j]+2*k] == 0) {
                    ok = false;
                    break;
                }
                mpp[nums[j]]--, mpp[nums[j]+2*k]--;
                res.push_back(nums[j]+k);
            }
            mpp = mp;
            if(ok) return res;
        }
        return {};
    }

};