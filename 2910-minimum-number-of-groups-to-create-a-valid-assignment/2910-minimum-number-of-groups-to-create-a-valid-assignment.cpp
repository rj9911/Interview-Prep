class Solution {
public:
    bool isPossible(unordered_map<int, int>& mp,int x) {
        for (auto it : mp) {
            int rem = it.second % x;
            int q = it.second / x;
            if (rem < x - 1) {
                int req = (x - 1) - rem;
                if (q >= req) rem = x - 1;
            }
            if (0 < rem && rem < x - 1) return false;
        }
        return true;
    }
    
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n = nums.size();
        int mini = n;
        unordered_map<int, int> mp;
        for (auto num:nums) mp[num]++;
        for (auto it:mp) mini = min(mini, it.second);
        for (int i = mini + 1; i > 0; i--) {
            if (isPossible(mp,i)) {
                int out = 0;
                for (auto it : mp) {
                    int rem = it.second % i;
                    out += it.second / i;
                    if (rem > 0) out++;
                }
                return out;
            }
        }
        return 0;
    }

};