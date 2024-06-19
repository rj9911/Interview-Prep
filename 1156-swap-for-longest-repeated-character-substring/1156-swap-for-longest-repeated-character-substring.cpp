class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size(),j = 0,maxi = 1;
        unordered_map<char,int> mp;
        for(auto it:text)   
            mp[it]++;
        if(mp.size() == 1)
            return n;
        while(j < n){
            int cnt_left = 1;
            while(j < n-1 && text[j] == text[j+1]){
                cnt_left++;
                j++;
            }
            char ch = text[j];
            int i = j + 2,cnt_right = 0,total = 0;
            while(i < n && ch == text[i]){
                cnt_right++;
                i++;
            }
            total = cnt_left + cnt_right;
            if(mp[ch] > total)
                maxi = max(maxi,total+1);
            else
                maxi = max(maxi,total);
            j++;
        }
        return maxi;
    }

};