class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < target.size(); i++) mp[target[i]] = i;
        vector<int> v;
        for(int a: arr) if (mp.count(a)) v.push_back(mp[a]);
        int n = v.size(), ans = 0;
        vector<int> tail(n + 1, INT_MAX);
        tail[0] = INT_MIN;
        for(int a: v) {
            int b = upper_bound(tail.begin(), tail.begin() + min(ans + 1, n), a) - tail.begin();
            if (b == 0 || (tail[b - 1] < a && tail[b] > a)) {
                tail[b] = a;
                ans = max(ans, b);
            }
        }
        return target.size() - ans;
    }

};