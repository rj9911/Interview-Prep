class Solution {
public:
 int minSubarray(vector<int>& nums, int p) {
   long long int sum=0;
     for(int i=0; i<nums.size(); i++){
          sum+=nums[i];
       }
        int rem=sum%p;
        if(rem==0)
            return 0;
int mn=nums.size();
unordered_map<int,int> m;
sum=0;
for(int i=0;i<nums.size() ;i++){
sum+=nums[i];
int k=sum%p;
if(k==rem)
 mn=min(mn,i+1);
 if(m.find(k-rem)!=m.end())
     mn=min(mn,i-m[k-rem]);
 if(m.find(k-rem+p)!=m.end())
 mn=min(mn,i-m[p+k-rem]);
     m[k]=i;            
  }
     if(mn>=nums.size())
     return -1;

 return mn;
    }
};