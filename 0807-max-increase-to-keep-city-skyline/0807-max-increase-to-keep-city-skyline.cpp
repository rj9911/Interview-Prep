class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        vector<int> row;
        vector<int> col;
        for (int i=0;i<r;i++){
            priority_queue<int> pq;
            for (int j=0;j<c;j++){
                pq.push(grid[i][j]);
            }
            row.push_back(pq.top());
        }
        for (int i=0;i<c;i++){
            priority_queue<int> pq;
            for (int j=0;j<r;j++){
                pq.push(grid[j][i]);
            }
            col.push_back(pq.top());
        }
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                ans+=min(row[i],col[j])-grid[i][j];
            }
        }
        return ans;
        
    }

};