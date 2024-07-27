class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        vector<int> maxFrequency(26, 0);
        for (char ch : s) {
            maxFrequency[ch - 'a']++;
        }

        vector<int> dp(s.length() + 1, INT_MAX);
        dp[0] = 0; // Base case: no characters, no partitions needed

        for (int i = 1; i <= s.length(); i++) {
            vector<int> freq(26, 0);
            int maxInWindow = 0;

            for (int j = i; j > 0; j--) {
                int index = s[j - 1] - 'a';
                freq[index]++;
                maxInWindow = max(maxInWindow, freq[index]);

                bool valid = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0 && freq[k] < maxInWindow) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[s.length()];
    }

};