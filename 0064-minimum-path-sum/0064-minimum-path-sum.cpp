class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        vector<vector<int>> d(n, vector<int>(m, 1e9));
        d[0][0] = grid[0][0];
        vector<int> dx = {0, 1}, dy = {1, 0};

        while(pq.size()) {
            int dis = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            if(i == n - 1 && j == m - 1) return dis;

            for(int k=0; k<2; k++) {
                int x = i + dx[k], y = j + dy[k];
                if(x < n && y < m && dis + grid[x][y] < d[x][y]) {
                    d[x][y] = dis + grid[x][y];
                        pq.push({d[x][y], {x, y}});
                }
            }
        }
        return -1;
    }
};