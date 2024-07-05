class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        using pi = pair<int, vector<int>>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int m = mat.size(), sum = 0;
        int n = mat[0].size(), curSum = 0;
        
        vector<int> v(m, 0);
        for(int i=0; i<m; i++){
            sum += mat[i][0];
        }
        
        pi p = make_pair(sum, v);
        set<vector<int>> st;
        pq.push(p), st.insert(v);
        
        while(k--){
            p = pq.top();
            pq.pop();
            v = p.second, sum = p.first;
            curSum = sum;
            for(int i=0; i<m; i++){
                if(v[i]+1 < n){
                    v[i]++;
                    if(!st.count(v)){
                        sum = sum + mat[i][v[i]] - mat[i][v[i]-1];
                        pq.push({sum, v}), st.insert(v);
                    }
                    sum = curSum;
                    v[i]--;
                }
            }    
        }
        return curSum;
    }

};