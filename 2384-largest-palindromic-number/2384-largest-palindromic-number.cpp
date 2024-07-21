class Solution {
public:
    string largestPalindromic(string num) 
    {
        map<char,int>mp;
        for(char ch:num) mp[ch]++;

        int mx = INT_MIN;
        for(auto [a, b]:mp)
        {
            if(b%2)
            {
                mp[a]--;
                mx = max(mx, a-'0');
            }
        }

        deque<char>opps;
        if(mx != INT_MIN) opps.push_back(mx + '0');

        for(auto [a, b]:mp)
        {
            while(b)
            {
                opps.push_back(a);
                opps.push_front(a);
                b -= 2;
            }
        }

        while(opps.size() > 1 and opps.front()=='0') opps.pop_front();
        while(opps.size() > 1 and opps.back()=='0') opps.pop_back();

        string ans;
        for(auto ch:opps) ans += ch;
        return ans;
    }

};