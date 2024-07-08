class Solution {
public:
    bool f(int maxi,int p,vector<int>&nums){
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=maxi){cnt++;i++;}
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int i=0,j=1e9;
        int ans=1e9;
        while(i<=j){
            int mid=(i+j)/2;
            if(f(mid,p,nums)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }

};