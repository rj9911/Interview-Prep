class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        unordered_map<int,bool> mp;
        sort(points.begin(),points.end());
        int ans=0;
        for(int i=0;i<points.size();i++){
            if(mp[i]==1){
                continue;
            }
            ans++;
            int j=i+1;
            int end=points[i][1];
            while(j<points.size()){
                if(points[j][0]<=end){
                    end=min(end,points[j][1]);
                    mp[j]=1;
                    i=j;
                    j++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }

};