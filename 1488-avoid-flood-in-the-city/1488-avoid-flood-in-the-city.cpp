class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
     vector<int>ans;
     unordered_map<int,int>mp;
     int size=rains.size();
       set<int>st; 
      for(int i=0;i<size;i++){
          if(rains[i]==0){
            st.insert(i);
              ans.push_back(1);
          }
          else{
              if(mp.find(rains[i])!=mp.end()){
                  auto it=st.lower_bound(mp[rains[i]]);
                  if(it==st.end())
                      return {};
                  ans[*it]=rains[i];
                  st.erase(*it);
              }
              mp[rains[i]]=i;
              ans.push_back(-1);
          }
      }
        return ans;
    }

};