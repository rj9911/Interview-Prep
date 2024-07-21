class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> curr(27,0),prev(27,0);

        for(int idx=0;idx<n;++idx) {
            for(int prevChar=0;prevChar<27;++prevChar) {
                char ch = prevChar + 'a';
                int take = 0;
                if(prevChar == 26 or abs(ch-s[idx]) <= k) take = 1 + (idx? prev[s[idx]-'a']:0);
                int notTake = (idx? prev[prevChar]:0);

                curr[prevChar] = max(take,notTake);
            }
            prev = curr;
        }
        return curr[26];
    }

};