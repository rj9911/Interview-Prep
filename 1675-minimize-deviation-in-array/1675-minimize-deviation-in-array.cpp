class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;
        int maxi = INT_MIN, mini = INT_MAX;

        for(int i=0;i<n;i++)
        {
            //Converting odd to even
            if(nums[i]%2 != 0)
            nums[i] *=2;
            
            maxi = max(maxi, nums[i]); //Maximum
            mini = min(mini, nums[i]); //Minimum
            pq.push(nums[i]);
        }

        int ans = maxi - mini;

        while(pq.top()%2 == 0)
        {
            int top = pq.top();
            pq.pop();

            ans = min(ans, top - mini); //Update ans everytime to get minimum deviaton.

            top /= 2;
            pq.push(top);
            mini = min(mini, top);
        }

        ans = min(ans, pq.top() - mini);
        return ans;

    }

};