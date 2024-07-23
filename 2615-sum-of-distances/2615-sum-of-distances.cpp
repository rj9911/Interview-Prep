class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans(nums.size());
        unordered_map<long long,vector<long long>> m;
        unordered_map<long long,long long> n;
        for(int i=0;i<nums.size();++i){
            n[nums[i]]=0;
            if(m.find(nums[i])!=m.end()){
                long long t = m[nums[i]].back();
                t += i;
                m[nums[i]].push_back(t);
            }
            else m[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();++i){
            if(m[nums[i]].size()==1)ans[i] = 0;
            else{
                ans[i] = m[nums[i]].back() - (i*(m[nums[i]].size()-n[nums[i]]-1)) - m[nums[i]][n[nums[i]]];
                if(n[nums[i]]>0)
                ans[i] += (n[nums[i]]+1)*i - m[nums[i]][n[nums[i]]];
            }
            n[nums[i]]+=1;
        }
        return ans;
    }

};