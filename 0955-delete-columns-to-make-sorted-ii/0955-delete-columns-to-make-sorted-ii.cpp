class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, m = size(strs), n = size(strs[0]); 
        vector<int> grp(m); 
        for (int j = 0; j < n; ++j) {
            bool found = false; 
            for (int i = 1; i < m; ++i) 
                if (grp[i-1] == grp[i] && strs[i-1][j] > strs[i][j]) {
                    ++ans; 
                    found = true; 
                    break; 
                }
            if (!found) 
                for (int i = 1; i < m; ++i) {
                    grp[i] = max(grp[i-1], grp[i]); 
                    if (grp[i-1] == grp[i] && strs[i-1][j] < strs[i][j]) grp[i] = i; 
                }
        }
        return ans; 
    }

};