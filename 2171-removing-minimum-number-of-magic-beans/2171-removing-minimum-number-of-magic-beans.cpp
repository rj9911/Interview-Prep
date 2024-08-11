class Solution {
public:
 long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long long rightSum[n];
        long long leftSum[n];
        leftSum[0]=0;
        rightSum[n-1]=0;
        
        for(int i=1;i<n;i++){
            leftSum[i]=beans[i-1]+leftSum[i-1];
        }
         for(int i=n-2;i>=0;i--){
            rightSum[i]=beans[i+1]+rightSum[i+1];
        }
        
        long long mi=LLONG_MAX;
        
        for(long long i=0;i<n;i++){
          
            mi=min( mi,leftSum[i] + (rightSum[i]-((long long)beans[i]*(long long)(n-i-1))) );  
        }
        
        return mi;
    }

};