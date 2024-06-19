class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(),mini = n + 1;
        long sum = 0;
        deque<pair<long,int>> dq;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum >= k)
                mini = min(mini,i + 1);
            while(dq.size() && dq.front().first <= sum - k){
                mini = min(mini,i - dq.front().second);
                dq.pop_front();
            }
            while(dq.size() && dq.back().first >= sum)
                dq.pop_back();
            dq.push_back({sum,i});
        }
        return (mini != n + 1) ? mini : -1;
    }

};