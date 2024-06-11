class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int n = fr.second.size();
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            vector<int> count(n + 1);
            count[n] = 1;
            for (int i = n - 1; i >= 0; i--) {
                int skip = count[i + 1];
                int take = (1 << s[i].second) - 1;
                if (i + 1 < n && s[i + 1].first - s[i].first == k) {
                    take *= count[i + 2];
                } else {
                    take *= count[i + 1];
                }
                count[i] = skip + take;
            }
            result *= count[0];
        }
        return result - 1;
    }

};