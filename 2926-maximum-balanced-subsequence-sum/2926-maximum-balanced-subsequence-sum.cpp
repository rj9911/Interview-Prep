class Solution {
public:
    #define ll long long

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> val(n);
        for(int i=0;i<n;i++){
            val[i]=nums[i]-i;
        }
        map<int,ll> mp;
        set<int> st;
        st.insert(val[0]);
        mp[val[0]]=nums[0];
        ll ans=nums[0];
        for(int i=1;i<n;i++){
            auto it=st.upper_bound(val[i]);
            if(it==st.begin()){
                mp[val[i]]=nums[i];
            }
            else{
                it--;
                mp[val[i]]=max(nums[i]+mp[*it],1LL*nums[i]);
            }
            it++;
            while(it!=st.end() and mp[*it]<=mp[val[i]] and *it>val[i]){
                st.erase(it++);
            }
            st.insert(val[i]);

            ans=max(ans,mp[val[i]]);
        }

        return ans;
    }

};