class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size(), len = 0, start = -1;
        for(int unique = 1; unique < 26; unique++) {
            int total[26] = {}, upper[26] = {}, lower[26] = {}, countLower = 0, countUpper = 0, count = 0;
            for(int right = 0, left = 0; right < n; right++) {
                if(isupper(s[right])) {
                    count += ++total[s[right] - 'A'] == 1;
                    countUpper += ++upper[s[right] - 'A'] == 1;
                } else {
                    count += ++total[s[right] - 'a'] == 1;
                    countLower += ++lower[s[right] - 'a'] == 1;
                }
                while(count > unique) {
                    if(isupper(s[left])) {
                        count -= --total[s[left] - 'A'] == 0;
                        countUpper -= --upper[s[left] - 'A'] == 0;
                    } else {
                        count -= --total[s[left] - 'a'] == 0;
                        countLower -= --lower[s[left] - 'a'] == 0;
                    }
                    left++;
                }
                if(count == countUpper && countLower == count && right - left + 1 > len) {
                    len = right - left + 1;
                    start = left;
                }
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }

};