class Solution {
public:
    int digSum(int n){
        int sum = 0;
        while(n){
            sum += (n%10);
            n/=10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(auto num : nums){
            mp[digSum(num)].push_back(num);
        }

        int ans = -1;

        for(auto i : mp){
            if(i.second.size() <= 1) continue;
            vector<int>v = i.second;
            sort(v.begin(),v.end(),greater<int>());
            ans = max(ans, v[0]+v[1]);
        }

        return ans;
    }
};