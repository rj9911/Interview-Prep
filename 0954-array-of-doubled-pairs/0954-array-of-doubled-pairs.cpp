class Solution {
public:
bool static comp(int &i, int &j)
    {
        if(i < 0 && j < 0)
            return i > j;
        else
            return i<j;
    }
    bool canReorderDoubled(vector<int>& changed) {
        unordered_map<int,int> mp;
        for(auto it: changed){
            mp[it]++;
        }
        
       sort(changed.begin(), changed.end(), comp); // applied customize sorting 
        for(auto it: changed) cout << it << " ";
        vector<int> ans;
        for(auto it: changed){
            if(mp[it] > 0){
                    mp[it]--;
                    ans.push_back(it);
                    
                    if(mp[it * 2] > 0){
                        mp[it * 2]--;
                    }
                    else{
                        return false;
                    }
            }
                
        }
    
        return true;
    }
};