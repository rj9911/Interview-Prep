class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> m;
        for(int i=0 ; i<g.size() ; i++)
            m[g[i]].push_back(i);
        
        vector<vector<int>> ans;
        for(auto x:m){
            vector<int> v;
            int y=x.first;

            for(int i=0 ; i<x.second.size() ; i++){
                v.push_back(x.second[i]);

                if(v.size()==y){
                    ans.push_back(v);
                    v.clear();
                }

            }

        }

        return ans;
    }

};