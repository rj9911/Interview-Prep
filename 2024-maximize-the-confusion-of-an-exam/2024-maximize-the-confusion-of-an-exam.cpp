class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, len = 0, mx = 0;

        while(r < ans.size()){
            char curr = ans[r];
            mp[curr]++;
            mx = max(mx, mp[curr]);

            while(r-l+1 - mx > k){
                mp[ans[l]]--;
                l++;
            }

            len = max(len, r-l+1);
            r++;
        }

        return len;
    }

};