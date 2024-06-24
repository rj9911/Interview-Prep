class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int, pair<int, pair<int, int>>> mp;
        int n = cards.size();

        for(int i = 0; i < n; i++) {
            int temp = cards[i];

            if(mp.find(temp) == mp.end()) {
                mp[temp] = {1, {-1, i}};
            }
            else if(mp[temp].first == 1) {
                int prev = mp[temp].second.second;
                mp[temp] = {2, {i-prev+1, i}};
            }
            else if(mp[temp].first == 2) {
                int prev = mp[temp].second.second;
                int old = mp[temp].second.first;
                if(i - prev+1 <= old) {
                    mp[temp] = {2, {i-prev+1, i}};
                }
                else {
                    mp[temp] = {2, {old, i}};
                }
            }
        }

        int res = INT_MAX; 

        for(auto x : mp) {
            if(x.second.first == 2) {
                res = min(res, x.second.second.first);
            }
        }
        
        return (res == INT_MAX) ? -1 : res;
    }

};