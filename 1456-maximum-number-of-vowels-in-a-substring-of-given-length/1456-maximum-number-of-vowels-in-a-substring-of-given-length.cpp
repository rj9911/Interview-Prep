class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0, j = 0;
        int maxi = INT_MIN;
        int count = 0;
        while(j < s.size()){
            char ch = s[j];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                count++;
            }
            if(j - i + 1 == k){
                maxi = max(maxi, count);
                ch = s[i];
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    count--;
                }
                i++;
            }
            j++;
        }
    return maxi;
    }

};