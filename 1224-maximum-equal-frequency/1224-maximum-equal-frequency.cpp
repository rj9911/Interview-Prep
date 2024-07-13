class Solution {
public:
 
    int maxEqualFreq(vector<int>& nums) {
        long long n=nums.size(),answer=INT_MIN,count=INT_MIN;
        unordered_map<long long,long long>mp,freq;
        for(long long i=0;i<n;i++){
            mp[nums[i]]++;
            count=max(count,mp[nums[i]]);
            freq[mp[nums[i]]]++;
            if(mp[nums[i]]>1){
                freq[mp[nums[i]]-1]--;
            }
            if(count==1){
                answer=max(answer,i+1);
            }
            else{
                if(mp.size()==1 && freq[i+1]==1){
                    answer=max(answer,i+1);
                }
                else if(freq[count]==mp.size()-1 && (freq[count+1]==1 || freq[1]==1)){
                    answer=max(answer,i+1);
                }
                else if(freq[count-1]==mp.size()-1 && freq[count]==1){
                    answer=max(answer,i+1);
                }
            }
        }
        return answer;
    }

};