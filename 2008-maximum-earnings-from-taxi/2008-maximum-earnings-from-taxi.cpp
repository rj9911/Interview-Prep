 bool comp(const vector<int> &v1,const vector<int> &v2){
    // comparing second values ie end times
    return v1[1]<v2[1];
}

class Solution {
public:

    
    long long maxTaxiEarnings(int n, vector<vector<int>>& v) {
        // sorting with ending values
        sort(v.begin(),v.end(),comp);
        int m=v.size();
        // changing vector with adding tip and distance both .. 
        for(int i=0;i<m;i++){
            // value+=(endTime-startTime)
            v[i][2]+=(v[i][1]-v[i][0]);
        }
        vector<long long > dp(m,0);
        dp[0]=v[0][2];
        for(int i=1;i<m;i++){
            // considering riding or not riding that taxi
            long long  nottake=dp[i-1];
            long long take=v[i][2];
            // if taking finding the latest taxi with start[end]<start[i]..
            int ind =-1;
            int l=0;
            int r=m-1;
            int start=v[i][0];
            // binary searching that taxi
            while(l<=r){
                int mid=(l+r)/2;
                if(v[mid][1]<=start){
                    ind=mid;
                    l=mid+1;
                }
                else {
                    r=mid-1;
                }
            }
            // if found adding that value to take 
            if(ind!=-1){
                take+=dp[ind];
            }
            // taking max of both cases
            dp[i]=max(take,nottake);
        }
        
        return dp[m-1];
    }

};