class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        long long cnt=0;
        int i=0,j=0;
        map<int,int> mp;
        map<int,bool> m;
        while(i<nums.size()){
            if(m.find(i) == m.end()){
                mp[nums[i]] += 1;
                m[i] = true;
                int x = mp[nums[i]];
                if(x > 1){
                    cnt += (x-1);
                }
            }
            if(cnt >= k){
                ans += (nums.size() - i);
                int y = mp[nums[j]];
                if(y > 1){
                    cnt -= (y-1);
                }
                mp[nums[j]] -= 1;
                m.erase(j);
                j+=1;
            }else{
                i+=1;
            }
        }
        return ans;
    }

};