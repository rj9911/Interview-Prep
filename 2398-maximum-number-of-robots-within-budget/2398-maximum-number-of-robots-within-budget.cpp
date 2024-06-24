class Solution {
public:
int maximumRobots(vector<int>& chargeTimes, vector<int>& rc, long long budget) {
        int l=0,r=0;
        int n=chargeTimes.size();
        priority_queue<pair<long long,long long>>pq;
        int ans=0;
        long long sum=0;
        while(r<n){
            sum+=rc[r];
            pq.push({chargeTimes[r],r});
            while(!pq.empty() && pq.top().second<l){
                pq.pop();
            }
            while(!pq.empty() && sum*(r-l+1)+pq.top().first>budget){
                sum-=rc[l];
                l++;
                
                while(!pq.empty() && pq.top().second<l){
                    pq.pop();
                }
                
                
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }

};