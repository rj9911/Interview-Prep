class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();  // Number of rows in the matrix
        int m = mat[0].size();  // Number of columns in the matrix

        int sum = 0;  // Initialize the total sum of all elements in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += mat[i][j];
            }
        }

        // Create a dynamic programming table to track if a sum is achievable
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;  // Initialize the sum of 0 as achievable

        // Iterate through each row of the matrix
        for (int i = 0; i < n; i++) {
            // Create a new dynamic programming table to track the updated sums
            vector<int> next_dp(sum + 1, 0);

            for (int j = 0; j <= sum; j++) {
                if (dp[j] == 1) {  // If the sum 'j' is achievable
                    for (int k = 0; k < m; k++) {
                        if (j + mat[i][k] <= sum) {
                            // Update the next_dp table to mark the new sum 'j + mat[i][k]' as achievable
                            next_dp[j + mat[i][k]] = 1;
                        }
                    }
                }
            }

            // Update the dp table with the new achievable sums
            dp = next_dp;
        }

        int ans = INT_MAX;
        // Find the minimum absolute difference between the target and achievable sums
        for (int i = 0; i <= sum; i++) {
            if (dp[i] == 1) {
                ans = min(ans, abs(target - i));
            }
        }

        return ans;  // Return the minimum absolute difference
    }

};