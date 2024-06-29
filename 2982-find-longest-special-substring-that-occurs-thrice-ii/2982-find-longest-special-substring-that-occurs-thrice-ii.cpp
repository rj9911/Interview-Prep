class Solution {
public:
    int maximumLength(string s){
        int n=s.size(), i=0, j=1, result=INT_MIN;
        unordered_map<string,int> mp;
        string temp="";
        temp+=s[0];
        while(j<n){
            if(s[j]==s[j-1]) temp+=s[j];
            else{
                int currLen=j-i-2;
                mp[temp]++;
                temp.pop_back();
                if(temp.size()>0) mp[temp]+=2;
                if(currLen>0) result=max(result,currLen);
                i=j;
                temp=s[j];
            }
        j++;
        }
        mp[temp]++;
        temp.pop_back();
        if(temp.size()>0) mp[temp]+=2;
        int currLen=j-i-2;
        if(currLen>0) result=max(result,currLen);
        for(auto it : mp){
            if(it.second>2){
                auto str=it.first.size();
                result=max(result,static_cast<int>(str));
            }
        }
    return result==INT_MIN ? -1 : result;        
    }

};