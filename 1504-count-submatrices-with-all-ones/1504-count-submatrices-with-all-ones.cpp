class Solution {
public:
   int numSubmat(vector<vector<int>>& matrix) {
        int n=matrix.size();
		int m=matrix[0].size();
		int count=0;
		vector<vector<int>> dp(n,vector<int>(m,0));

		for(int i=0;i<n;i++){
			for(int j=m-1;j>=0;j--){
                if(matrix[i][j]==1){
                    if(j == m-1) dp[i][j]++;
                    else dp[i][j]=dp[i][j+1]+1;
                } else dp[i][j] = 0;
			}
		}

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int mn = dp[i][j];
                for(int k=i;k<n;k++){
                    mn = min(mn,dp[k][j]);
                    count += mn;
                }
            }
        }

        return count;

    }
};