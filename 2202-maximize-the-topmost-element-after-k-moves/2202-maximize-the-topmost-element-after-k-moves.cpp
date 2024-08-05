class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0)return nums[0];
        int ans=-1;
        if(k==1&&nums.size()==1)return -1;
        if(nums.size()==1 && k%2==1)return -1;
        if(k==1 && nums.size()>1)return nums[1];
        if(k>nums.size())
        {
            return *max_element(nums.begin(),nums.end());
        }
        else
        {
            queue<int>q;
            for(int i=0;i<nums.size();i++)
            {
                q.push(nums[i]);
            }
        
                int t=k-1;
                while(t>0)
                {
                    
                    ans=max(ans,q.front());
                    q.pop();
                    t--;
                    
                }
               if(q.size()>1)
               {
                   q.pop();
                    if(ans<q.front())
                    {
                        return q.front();
                    }
               }
        }
        return ans;
    }

};