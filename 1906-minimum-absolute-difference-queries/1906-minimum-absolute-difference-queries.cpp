class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> finala;
        // Precompute prefix frequencies
        vector<vector<int>> prefix(n + 1, vector<int>(101, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 100; ++j) {
                prefix[i + 1][j] = prefix[i][j];
            }
            prefix[i + 1][nums[i]]++;
        }

        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            vector<int> store(101, 0);
            
            // Get frequency of each number in the range [left, right]
            for (int j = 1; j <= 100; ++j) {
                store[j] = prefix[right + 1][j] - prefix[left][j];
            }
            
            int prev = -1;
            int ans = INT_MAX;

            // Find the minimum difference
            for (int j = 1; j <= 100; ++j) {
                if (store[j] > 0) {
                    if (prev != -1) {
                        ans = min(ans, j - prev);
                    }
                    prev = j;
                }
            }

            if (ans == INT_MAX) {
                ans = -1;
            }

            finala.push_back(ans);
        }

        return finala;
    }

};