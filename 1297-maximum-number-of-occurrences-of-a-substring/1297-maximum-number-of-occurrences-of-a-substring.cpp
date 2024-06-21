class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        unordered_map<string, int> mp2;
        unordered_map<char, int> mp;
        int distinct = 0;
        int i=0, j=0;
        int cnt = 0;
        while(j < s.size())
        {
            if(mp[s[j]] == 0) distinct++;
            mp[s[j]]++;
            while(j-i+1 > maxSize || distinct > maxLetters)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0) distinct--;
                i++;
            }
            while(j-i+1 >= minSize && distinct <= maxLetters)
            {
                mp2[s.substr(i, j-i+1)]++;
                mp[s[i]]--;
                if(mp[s[i]] == 0) distinct--;
                i++;
            }
            j++;
        }      
        for(auto it : mp2)
        {
            cnt = max(cnt, it.second);
        }
        return cnt;
    }

};