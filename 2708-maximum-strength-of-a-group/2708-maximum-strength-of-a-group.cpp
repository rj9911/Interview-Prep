class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        priority_queue<int, vector<int>, greater<int>> pq;

        long long prod = 1;
        bool isUpdated = false;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)        continue;
            else if(nums[i]>0)
            {
                prod *= nums[i];
                isUpdated = true;
            }    
            else                  pq.push(nums[i]);
        }

        while(pq.size()>1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            prod *= (x*y);
            isUpdated = true;
        }

        if(!isUpdated)    return 0;
        return prod;
    }

};