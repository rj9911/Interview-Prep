class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
      int m = a.size()-1;
      int i = 0;
      while(i<m){
        if(a[i]!=b[i]) return a[i]>b[i];
        i++; 
      }
      return a[m]<b[m];
    }
    string rankTeams(vector<string>& votes) {
      int n = votes.size(), m = votes[0].size();
      map<char, vector<int>> mp;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        char x = votes[i][j];
        vector<int>& vec = mp[x];
        vec.resize(m + 1);
        vec[j]++;
        vec[m] = x-'A';
        mp[x] = vec;
        }
      }
      vector<vector<int>> vec;
      for(auto i : mp){
        char x = i.first;
        vector<int> v = mp[x];
        v.resize(m+1);
        v[m] = x-'A';
        vec.push_back(v);
      }
      sort(vec.begin(), vec.end(), cmp);
      string ans;
      for(int i=0;i<vec.size();i++) ans.push_back(vec[i][m]+'A');
      return ans;

    }

};