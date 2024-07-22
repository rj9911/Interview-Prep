class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        vector<int> pre(n,0);
       
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            
                int c=nums[i]%value;
                if(nums[i]<0)
                {
                    int ck=abs(nums[i])/value;
                    if(abs(nums[i])%value>0) ck++;
                    nums[i]+=ck*value;
                    c=nums[i]%value;
                }
                mp[c]++;
            
        }
     
        for(int i=0;i<n;i++)
        {    
            pre[i]=0;
            int c=i%value;
            if(mp.count(c)==1)
            {
                pre[i]=1;
                mp[c]--;
                if(mp[c]==0) mp.erase(c);
            }
        }
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(pre[i]==0) 
            {
                ans=i;
                break;
            }
        }
        return ans;
       
    }

};