class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size(),m=pattern.size();
        vector<bool> ans;
        for(int i=0;i<n;i++){
            int j=0,k=0;
            string ss;
            while(j<queries[i].size() && k<pattern.size()){
                if(queries[i][j]==pattern[k]){
                    ss+=pattern[k];
                    k++;
                }
                //At this point we find that there is a camel case in queries[i] which is not in pattern
                else if(queries[i][j]>=65 && queries[i][j]<=90) break;
                j++;
            }
            //Check if after we have found the match we have any camel case character left
            while(j<queries[i].size()){
                if(queries[i][j]>=65 && queries[i][j]<=90){
                    break;
                }
                j++;
            }
            ans.push_back(j>=queries[i].size() && k>=pattern.size() && ss==pattern);
        }
        return ans;
    }

};