class Solution {
public:
    int balancedString(string s) 
    {
        int len=s.length();
        int letter_count=len/4;
        unordered_map<char,int>map;//storing the count of the characters in the map
        for(auto ch:s)
            map[ch]++;
        for(auto it:"QWER")//removing all the characters whose count is less than letter_count
        {
            if(map[it]<=letter_count)
                map.erase(it);
            else
                map[it]-=letter_count;
        }
        if(map.size()==0)return 0;
        unordered_map<char,int>map2=map;
        int i=0,j=0;
        int min_replace=len;
        int msize=map2.size();
        while(j<len)
        {
            if(map2.find(s[j])!=map2.end())
            {
                map2[s[j]]--;
                if(map2[s[j]]==0)
                    msize--;
            }
            while(i<=j && msize==0)
            {
                min_replace=min(min_replace,j-i+1);
                if(map.find(s[i])!=map.end())
                {
                    map2[s[i]]++;
                    if(map2[s[i]]>0)
                        msize++;
                }
                i++;
            }
            j++;
        }
        return min_replace;
    }

};