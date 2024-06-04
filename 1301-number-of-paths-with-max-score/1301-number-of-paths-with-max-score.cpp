class Solution {
public:
	vector<int> pathsWithMaxScore(vector<string>& board) {
		int tomod=(1e9+7);
		int n=board.size();
		vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		vector<vector<int>> path(n+1,vector<int>(n+1,0));
		path[n-1][n-1]=1;
		board[0][0]='0';
		board[n-1][n-1]='0';
		int cur;
		for(int i=n-1;i>=0;i--)
			for(int j=n-1;j>=0;j--){
				if(board[i][j]!='X'){
					cur=max(max(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1]);
					//cout<<cur<<endl;
					dp[i][j]=cur+(board[i][j]-'0');
				if(dp[i+1][j]==cur){
					//cout<<path[i][j]<<endl;
					path[i][j]=(path[i][j]+path[i+1][j])%tomod;
				}
				if(dp[i][j+1]==cur){
					//cout<<path[i][j]<<endl;
					path[i][j]=(path[i][j]+path[i][j+1])%tomod;
				}
				if(dp[i+1][j+1]==cur){
					//cout<<path[i][j]<<endl;
					path[i][j]=(path[i][j]+path[i+1][j+1])%tomod;
				}
				}


			}
		return {path[0][0] ? dp[0][0]:0 , path[0][0]};

	}

};