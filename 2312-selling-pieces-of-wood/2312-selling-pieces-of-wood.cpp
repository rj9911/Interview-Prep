class Solution {
public:
	long long sellingWood(int m, int n, vector<vector<int>>& prices) {     
		//Base case is tackled in this declaration as we initialized the dp array with 0.
		vector<vector<long long>> dp(m+1,vector<long long>(n+1,0)); 

		//Storing Prices in dp array itself
		for(int i = 0;i < prices.size();i++)
			dp[prices[i][0]][prices[i][1]] = prices[i][2];

		for(int row = 1;row <= m;row++){ //loop reversed
			for(int col = 1;col <= n;col++){ //loop reversed

				//Base Case is tackled under this
				long long ans = dp[row][col]; 

				for(int i = 1;i <= row/2;i++)  //Partitions Row-wise
					ans = max(ans,dp[i][col] + dp[row-i][col]);

				for(int j = 1;j <= col/2;j++) //Partitions Column-wise
					ans = max(ans,dp[row][j] + dp[row][col-j]);

				//store ans in dp array before returning so that we can use it again.
				dp[row][col] = ans;
			}
		}

		return dp[m][n];
	}

};