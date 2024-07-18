class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        vector<long long>prefix(nums.size()),suffix(nums.size());
        prefix[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        suffix[nums.size()-1]=nums.back();
        for(int i= nums.size()-2; i>=0; i--){
            suffix[i]=nums[i]+suffix[i+1];
        }
        map<long long,long long>m,left;
        long long ans=INT_MIN;
        for(int i=0; i<nums.size()-1; i++){
            m[prefix[i]-suffix[i+1]]++;
        }
        ans=max(ans,m[0]);
        for(int i=0; i<nums.size(); i++){
            ans=max(ans,left[k-nums[i]]+m[nums[i]-k]);
            if(i+1<nums.size()){
                left[prefix[i]-suffix[i+1]]++;
                m[prefix[i]-suffix[i+1]]--;
                if(m[prefix[i]-suffix[i+1]]==0) m.erase(prefix[i]-suffix[i+1]);
            }
        }
        return (int)ans;
    }

};