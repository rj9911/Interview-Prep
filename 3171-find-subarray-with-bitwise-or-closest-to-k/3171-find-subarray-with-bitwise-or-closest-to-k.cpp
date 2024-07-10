class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX,len=nums.size(),currNum,bitIndex,currXor=0,sum=0,start=0;
        vector<vector<int>> preXor(len,vector<int>(32,0));
        
        for(int index=0;index<nums.size();index++) {
            bitIndex=31;
            currNum=nums[index];
        
            while(currNum>0) {
                preXor[index][bitIndex]=currNum%2;
                currNum/=2;
                bitIndex--;
            }
        }
        
        for(bitIndex=31;bitIndex>=0;bitIndex--) {
            sum=0;
            for(int index=0;index<nums.size();index++) {
                sum+=preXor[index][bitIndex];
                preXor[index][bitIndex]=sum;
            }
        }   
        
        for(int index=0;index<nums.size();index++) {
            currXor=currXor|nums[index];
            ans=min(ans,abs(currXor-k));
           // cout<<start<<" "<<currXor<<endl;
            while(start<index && currXor>k) {
                currNum=currXor;
                for(bitIndex=31;bitIndex>=0;bitIndex--) {
                    if(currNum%2==1 && preXor[index][bitIndex]-preXor[start][bitIndex]==0)
                        currXor-=pow(2,31-bitIndex);
                    currNum/=2;
                }
                //cout<<start<<"I "<<currXor<<endl;
                start++;
                ans=min(ans,abs(currXor-k));
            }
        }
        
        return ans;
        
    }



};