class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int r = ages.size()-1;
        int l = ages.size()-2;
        int tot = 0;
        int streak = 1;
        while(r > 0){
            while((l>=r) || l >= 0 && ages[l] > 0.5 * ages[r]+7){
                if(ages[l] == ages[l+1] && ages[l] > 14){
                    streak++;
                }
                else{
                    tot+= streak*(streak-1)/2;
                    streak = 1;
                }
                l--;
            }
            l++;
            tot+= r-l;
            r--;
            l--;
        }
        tot+= streak*(streak-1)/2;
        return tot;
    }


};