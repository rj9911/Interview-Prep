class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if (s1==s2){
            return true;
        }
        int l1;
        for (int i=0;i<s1.size();i++){
            if (s1[i]>=s2[i]){
                l1=0;
            }
            else {
                l1=1;
                break;
            }
        }
        if (l1==0){
            return true;
        }
        int l2;
        for (int i=0;i<s1.size();i++){
            if (s1[i]<=s2[i]){
                l2=0;
            }
            else {
                l2=1;
                break;
            }
        }
        if (l2==0){
            return true;
        }
        return false;
    }

};