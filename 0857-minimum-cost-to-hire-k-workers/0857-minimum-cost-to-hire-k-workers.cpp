class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>> ratio(n);
        for(int i=0;i<n;i++){
            ratio[i].first=(double)quality[i]/(double)wage[i];
            ratio[i].second=quality[i];
        }
        sort(ratio.begin(),ratio.end());
        priority_queue<double> pq;
        int cnt=0;
        for(int i=n-1;i>=n-k;i--){
            pq.push(ratio[i].second);
            cnt+=ratio[i].second;
        }
        double ans=cnt/ratio[n-k].first;
        for(int i=n-k-1;i>=0;i--){
            if(pq.top()>ratio[i].second){
                cnt-=pq.top();
                cnt+=ratio[i].second;
                pq.pop();
                pq.push(ratio[i].second);
            }
            double sum=cnt/ratio[i].first;
            ans=min(ans,sum);
        }
        return ans;

    }

};