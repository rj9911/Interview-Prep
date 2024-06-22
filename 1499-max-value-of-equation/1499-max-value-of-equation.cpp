class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        int n=p.size();
        int mx = -1e9;
        deque<int> dq;
        int i=1;
        dq.push_back(0);
        while(i<n){
            while(!dq.empty() && p[i][0]-p[dq.front()][0]>k){
                dq.pop_front();
            }
            if(!dq.empty()){
                mx = max(mx,p[i][1]+p[i][0]+p[dq.front()][1]-p[dq.front()][0]);
            }
            while(!dq.empty() && p[dq.back()][1]-p[dq.back()][0]<p[i][1]-p[i][0]){
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        return mx;
    }

};