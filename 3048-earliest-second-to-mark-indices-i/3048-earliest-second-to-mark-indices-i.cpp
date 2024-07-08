class Solution {
public:
    bool isPossible(vector<int> &nums,vector<int> &changeIndicesZeroBased, int s){
        int n = nums.size();
        vector<int> last(n,-1);
        for(int i=0;i<=s;i++){
            last[changeIndicesZeroBased[i]]=i;
        }
        int completed=0,power=0;
        for(int i=0;i<=s;i++){
            if(i==last[changeIndicesZeroBased[i]]){
                if(nums[changeIndicesZeroBased[i]]>power) return false;
                power -= nums[changeIndicesZeroBased[i]];
                completed++;
            }
            else{
                power++;
            }
        }
        return completed==n;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n=nums.size(),m=changeIndices.size();
        vector<int> changeIndicesZeroBased=changeIndices;
        for(auto &el: changeIndicesZeroBased) el--;

        int low=0,high=m-1,ans=-1;
        while(low<=high){
            int mid = high + (low-high)/2;
            if(isPossible(nums,changeIndicesZeroBased,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans == -1 ? -1 : ans+1;
    }

};