class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l=0,r=0;
        long long res=0;
        int n=nums.size();
        long long sum=0;
        int start=-1,end=-1;
        while(r<n){
            long long len=r-l+1;
            sum+=nums[r];
            r++;
            while(r<n){
                if((long)(sum+nums[r])*(len+1)<k){
                    sum+=nums[r];
                    len++;
                    r++;
                }else{
                    break;
                }
                
            }
            
            while((long)sum*len>=k){
                sum-=nums[l];
                l++;
                len--;
            }
            
            long long val=len*(len+1)/2;
            res+=val;
            
            //reducing the count of those which have been counted
            if(start!=-1 and end-1>=l){
                long long s=end-l;
                long long d=s*(s+1)/2;
                res-=d;
            }
            start=l;
            end=r;
        }
        
        return res;
    }

};