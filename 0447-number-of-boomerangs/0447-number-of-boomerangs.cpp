class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int res=0;
        for(int i=0;i<n;i++){
        map<int,int>m;
            for(int j=0;j<n;j++){
                if(i!=j){
                int dist_ij= (pow(abs(points[i][0]-points[j][0]),2)+pow(abs(points[i][1]-points[j][1]),2));
                    m[dist_ij]++;
                }
            }
            for(auto it:m){
                res+= it.second* (it.second-1);
            }
        }
        return res;
        
    }

};