class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> ones;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
                ones.push_back(i);
        }
         int n=ones.size();
          vector<long long int> preSum(n, 0);
         preSum[0] = ones[0];
        for(int i=1;i<n;i++)
            preSum[i] = preSum[i-1] + ones[i];
        int i=0,j=0;
       long long int ans  = LLONG_MAX;
        while(j < n){
            if(j-i+1 == k){
                // cout<<"Hello"<<endl;
                int mid = (j + i)/2;
                long long int right = preSum[j] - preSum[mid];
                long long int left = (mid-1 < 0 ? 0 : preSum[mid - 1]) - (i-1 < 0 ? 0 : preSum[i-1]);
             // cout<<mid<<" "<<left<<" "<<right<<endl;
                int radius = (k-1)/2;
                long long int p = (long long int)radius*(radius + 1);
                long long int sum = right - left - p;
                if(k % 2 == 0){
                    sum -= (radius + 1);
                    sum -= ones[mid];
                }
               // cout<<sum<<endl;
                ans = min(ans, sum);
                i++;
            }
            j++;
        }
        return ans;
    }

};