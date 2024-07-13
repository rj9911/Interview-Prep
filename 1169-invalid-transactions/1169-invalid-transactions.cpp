class Solution {
public:
    vector<string> invalidTransactions(vector<string>& trans) {
        map<string,vector<pair<string,pair<int,int>>>>mp;
        int n=trans.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            string name,city;
            int time=0,cost=0;
            string s=trans[i];
            int j=0;
            while(s[j]!=',') name+=s[j++];
            j++;
            while(s[j]!=',') time=time*10+(s[j++]-'0');
            j++;
            while(s[j]!=',') cost=cost*10+(s[j++]-'0');
            j++;
            while(j<s.length()) city+=s[j++];
            if(!mp[name].empty()){
                for(auto t:mp[name]){
                    string last_city=t.first;
                    int last_time=t.second.first;
                    int last_idx=t.second.second;
                    if(last_city!=city && abs(time-last_time)<=60){
                        arr[last_idx]=1;
                        arr[i]=1;
                    }
                }
            }
            mp[name].push_back({city,{time,i}});
            if(cost>1000) arr[i]=1;
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                ans.push_back(trans[i]);
            }
        }
        return ans;
    }

};