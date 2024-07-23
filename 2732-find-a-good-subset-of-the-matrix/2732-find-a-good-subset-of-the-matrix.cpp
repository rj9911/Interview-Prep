class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<int> res;

        for(int i=0;i<n;i++){
            int c = m-1;
            int s = 0;
            for(int j=m-1;j>=0;j--){
                s += (v[i][j] * pow(2,c));
                c--;
            }
            res.push_back(s);
        }

        if(res[0] == 0) return {0};

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((res[j] & res[i]) == 0){
                    return {i,j};
                }
            }
        }

        return {};
    }

};