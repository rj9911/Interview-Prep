class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int> v(61,0);
        long long int ans = 0,y=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            while(i<n-1&&nums[i]==nums[i+1])i++;
            int x = 0,a = nums[i];
            while(a){
                x += (a&1);
                a >>= 1;
            }
            if(x*2>=k){
                y++;
            }
            for(int i = max(k-x,0); i<= 60; i++){
                ans += v[i];
            }
            v[x]++;
        }
        return ans*2+y;
    }

};