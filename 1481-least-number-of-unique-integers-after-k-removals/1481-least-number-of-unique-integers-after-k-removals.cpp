class Solution {
public:
static bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    return a.second < b.second;
}
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]++;
       vector<pair<int,int>>v;
        for(auto it:mp){
           v.push_back(it);
        }
        sort(v.begin(),v.end(),cmp);
      int c=0;
      for(auto it:v){
          if(it.second<=k) {
              c++;
              k-=it.second;
          }
          else break;
      }
      return v.size()-c;
    }

};