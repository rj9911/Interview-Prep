class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int>v(1001,1);
        vector<int>primes;
        for(int i=2;i<1001;i++){
            if(v[i])primes.push_back(i);
            else continue;
            // cout<<i<<"-";
            for(int j=i*i;j<1001;j+=i)v[j]=0;
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])continue;
            int l=0;
            int r=primes.size()-1;
            int p=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(primes[mid]>=nums[i])r=mid-1;
                else if(primes[mid]<nums[i]){
                    if(nums[i]-primes[mid]>=nums[i+1])l=mid+1;
                    else {
                        p=mid;
                        r=mid-1;
                    }
                }
            }
            // if(p!=-1)cout<<nums[i]<<"-"<<primes[p]<<"\n";
            if(p==-1)return 0;
            nums[i]-=primes[p];
        }
        return 1;
    }

};