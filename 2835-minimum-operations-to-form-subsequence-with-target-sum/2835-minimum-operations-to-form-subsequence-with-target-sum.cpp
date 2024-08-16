class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n=nums.size();
        int use=target;
        priority_queue<int> pq;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        if(sum<target){
            return -1;
        }
        int ans=0;
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            if(a<=target){
                target-=a;
            }else if((sum-(use-target)-a)<target){
                if(target>=a/2){
                    target-=a/2;
                    pq.push(a/2);
                }else{
                    pq.push(a/2);
                    pq.push(a/2);
                }
                ans++;
            }else if((sum-(use-target)-a)>=target){
                sum-=a;
            }
            if(target==0){
                return ans;
            }
        }
        return 0;
    }

};