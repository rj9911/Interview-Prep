class Solution {
public:
     int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int i=0,j=0;
        map<char,int> mp;
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]=vals[i];
        }
        int sum=0;
        int maxi=INT_MIN;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                sum+=mp[s[j]];
            }else{
                sum+=(s[j]-'a' + 1);
            }
            while(i<=j && sum<=0){
                if(mp.find(s[i])!=mp.end()){
                sum-=mp[s[i]];
            }else{
                sum-=(s[i]-'a' + 1);
            }
                i++;
            }
            maxi=max(maxi,sum);
            j++;
        }
        if(maxi<0){
            return 0;
        }
        return maxi;
    }

};