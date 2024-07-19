class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int nums[26] = {0};
        string curr = "aa";
        unordered_map<string, int> us;
        int duplicates = 0, ans = 0;
        
        for (string & s : words) {
            if (s[0] == s[1]) {
                nums[s[0] - 'a']++;
                continue;
            }
            
            curr[0] = s[1];
            curr[1] = s[0];
            if (us[curr] > 0) {
                ans = ans + 4;
                us[curr]--;
            } else {
                us[s]++;
            }
        }
        
        bool toAdd = false;
        for (int i = 0; i < 26; i++) {
            ans = ans + (nums[i] >> 1) * 4;
            if (nums[i] % 2 != 0) toAdd = true;
        }
        
        if (toAdd)
            return ans + 2;
        return ans;
    }
};