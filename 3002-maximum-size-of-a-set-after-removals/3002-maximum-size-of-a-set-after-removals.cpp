class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int>mp;
        unordered_set<int>st(nums1.begin(), nums1.end());
        unordered_set<int>st2(nums2.begin(), nums2.end());
        for(auto it : st){
            mp[it]++;
        }
        for(auto it : st2){
            mp[it]++;
        }
        int nn = n / 2, mm = nn;
        unordered_set<int>ans;
        int common = 0;
        for(auto it : mp){
            if(it.second == 2) common ++;
        }
        for(auto it : st){
            if(mp[it] == 1 && nn > 0){
                ans.insert(it);
                nn --;
            }
        }
        for(auto it : st2){
            if(mp[it] == 1 && mm > 0){
                ans.insert(it);
                mm --;
            }
        }
        return ans.size() + min(common, mm + nn);
        
    }

};