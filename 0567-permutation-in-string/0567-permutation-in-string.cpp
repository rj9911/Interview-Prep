class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;

        map<char,int> mp;
        for(auto x: s1)
        mp[x]++;

        int k = s1.length();
        int cnt = mp.size();
        int n = s2.size();
        int i=0,j=0;
        while(j<n)
        {
          if(mp.find(s2[j])!=mp.end())
          {
              mp[s2[j]]--;
              if(mp[s2[j]]==0)
              cnt--;
          }
          if(j-i+1<k)
          j++;

          else if(j-i+1==k)
          {
              if(cnt==0)
              return true;
                  if(mp.find(s2[i])!=mp.end()){
                  mp[s2[i]]++;
                  if(mp[s2[i]]==1)
                  cnt++;
                  }
                i++;
                j++;
              }
          }
        return false;
    }

};