class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix){
        int n=matrix.size(),m=matrix[0].size();
        map<string,int> mp;
        for(int i=0;i<n;i++){
            string str;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1) str.push_back('1');
                else str.push_back('0');
            }
            string rev;
            for(int j=0;j<m;j++){
                if(str[j]=='1') rev.push_back('0');
                else rev.push_back('1');
            }
            if(mp[str]>mp[rev]) mp[str]++;
            else mp[rev]++;
        }
        int ans=1;
        for(auto i:mp) ans=max(ans,i.second);
        return ans;
    }

};