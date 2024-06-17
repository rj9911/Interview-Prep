class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        // m = number of rows
        int m = grid.size();
        // n = number of columns
        int n = grid[0].size();
        vector<vector<int>> v(n, vector<int>(10));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                // count of every element (from 0 to 9) in each column
                v[i][grid[j][i]]++;
        }
        
        vector<vector<int>> dp(n, vector<int>(10, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
            // (m - v[i][j]) => number of operations required to make elements in (i)th column equal to j
                dp[i][j] = m - v[i][j];
                int mini = INT_MAX;
                if(i != 0){
                    for(int k = 0; k < 10; k++){
                        if(j != k)
                        // Finding the minimum number of operations in column i-1 required to make every element equal such that the element is not equal to element of column i i.e j 
                            mini = min(mini, dp[i-1][k]);
                    }
                }
                if(mini != INT_MAX)
                    dp[i][j] += mini;
            }
        }
        
        int res = INT_MAX;
        for(int i = 0; i < 10; i++)
            res = min(res, dp[n-1][i]);
        
        return res;
    }

};