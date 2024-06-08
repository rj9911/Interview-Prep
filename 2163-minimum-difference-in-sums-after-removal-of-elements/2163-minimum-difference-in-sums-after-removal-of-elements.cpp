class Solution {
public:
 long long minimumDifference(vector<int>& nums) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> min_q;
        priority_queue<long long int> max_q;
        int n=nums.size();
        long long int sum=0;
        vector<long long int> pre(n),suff(n);
        int k=n/3;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            max_q.push(nums[i]);
            if(max_q.size()>k){
                sum-=(max_q.top());
                max_q.pop();
            }
            if(max_q.size()>=k){
                pre[i]=sum;
            }
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            min_q.push(nums[i]);
            if(min_q.size()>k){
                sum-=(min_q.top());
                min_q.pop();
            }
            if(min_q.size()>=k){
                suff[i]=sum;
            }
            
        }
        long long ans=LONG_MAX;
        for(int i=k-1;i<n-k;i++){
            ans=min(ans,pre[i]-suff[i+1]);
        }
        return ans;


    }

};