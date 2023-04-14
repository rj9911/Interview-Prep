class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<bool>> vis(n,vector<bool>(m,false));
	    vector<vector<int>> dis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==0)
	            {
	                q.push({{i,j},0});
	                vis[i][j]=true;
	            }
	        }
	    }
	    int dr[]={-1,1,0,0};
	    int dc[]={0,0,-1,1};
	    while(!q.empty())
	    {
	        auto it=q.front();
	        int row=it.first.first;
	        int col=it.first.second;
	        int st=it.second;
	        q.pop();
	        dis[row][col]=st;
	        
	        for(int i=0;i<4;i++)
	        {
	            int nrow=row+dr[i];
	            int ncol=col+dc[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]!=0)
	            {
	                vis[nrow][ncol]=true;
	                q.push({{nrow,ncol},st+1});
	            }
	        }
	        
	    }
	    return dis; 
    }
};