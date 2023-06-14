class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int r=grid.size(),cnt=0;
        int c=grid[0].size();
        bool isEqual = true;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               for(int k=0;k<r;k++){
                   if(grid[i][k] != grid[k][j]){
                       isEqual=false; break;
                   }
               }  
               if(isEqual) cnt++;
               else isEqual = true;
            }
        }
        
        return cnt;
    }
};