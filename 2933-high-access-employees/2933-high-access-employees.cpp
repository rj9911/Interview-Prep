class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<long>>mp;
        vector<string>ans;
        for(int i=0;i<access_times.size();i++){
            string name=access_times[i][0];
            long time=stol(access_times[i][1]);
            mp[name].push_back(time);
        }
        for(auto x:mp){
            if(x.second.size()>=3){
                vector<long>temp;
                sort(x.second.begin(),x.second.end());
                for(auto y:x.second){
                    temp.push_back(y);
                }
            for(int i=0;i<temp.size()-2;i++){
                int start=temp[i];
                int len=start/1000;
                int target=start;
                    target=target+100;
                if(temp[i+2]<target && temp[i+2]<=2359){
                    ans.push_back(x.first);
                    break;
                }
                }    
            }
        }
        return ans;
    }

};