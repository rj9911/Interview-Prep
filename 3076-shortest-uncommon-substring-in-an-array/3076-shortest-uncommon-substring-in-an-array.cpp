class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr){
        int n = arr.size();
        map<string,set<int>> occurences;
        for(int id = 0 ; id < n ; id++){
            int m = arr[id].size();
            for(int i = 0 ; i < m ; i++){
                string currStr = "";
                for(int j = i ; j < m ; j++){
                    occurences[currStr+=arr[id][j]].insert(id);
                }
            }
        }
        
        vector<string> answer(n,"");
        for(int id = 0 ; id < n ; id++){
            int m = arr[id].size() , found = 0;
            for(int len = 1 ; len <= m && !found ; len++){
                for(int i = 0 ; i <= m - len ; i++){
                    string currStr = arr[id].substr(i,len);
                    if(occurences.find(currStr) != occurences.end() && occurences[currStr].size() == 1){
                        if(!found) answer[id] = currStr;
                        else answer[id] = min(answer[id],currStr);
                        found = 1;
                    }
                }
            }
        }

        return answer;
    }

};