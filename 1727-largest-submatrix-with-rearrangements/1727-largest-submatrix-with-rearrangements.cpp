class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]!=0)matrix[i][j]+=matrix[i-1][j];
            }
        }
        int maxarea=INT_MIN;
        for(int i=0; i<n; i++){
            sort(matrix[i].begin(), matrix[i].end(),greater<int>());
            int temp=INT_MAX;
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0)continue;
                temp=min(temp,matrix[i][j]);
                int area=(j+1)*temp;
                maxarea=max(maxarea,area);
            }
        }
        if(maxarea==INT_MIN)return 0;
        return maxarea;
    }

};