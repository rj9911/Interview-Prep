class Solution {
public:
#include <vector>
#include <algorithm>
#include <climits>

int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int dp[n][m];
    dp[0][0] = nums1[0] * nums2[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = std::max(dp[i - 1][0], nums1[i] * nums2[0]);
    }

    for (int j = 1; j < m; j++) {
        dp[0][j] = std::max(dp[0][j - 1], nums1[0] * nums2[j]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int val = std::max(dp[i][j - 1], dp[i - 1][j]);
            dp[i][j] = std::max({val, dp[i - 1][j - 1] + nums1[i] * nums2[j], nums1[i] * nums2[j]});
        }
    }

    return dp[n - 1][m - 1];
}


};