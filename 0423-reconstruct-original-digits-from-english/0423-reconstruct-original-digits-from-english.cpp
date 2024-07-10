class Solution {
public:
    string originalDigits(string s) {
        vector<int> alphabet(26,0);
        for(char &ch : s){
            alphabet[ch-'a']++;
        }
        vector<pair<char,pair<string,int>>> word =  {{'z', {"zero", 0}}, {'x', {"six", 6}}, {'s', {"seven", 7}}, 
		{'w', {"two", 2}}, {'u', {"four", 4}}, {'o', {"one", 1}}, {'r', {"three", 3}}, {'f', {"five", 5}}, 
		{'h', {"eight", 8}}, {'i', {"nine", 9}}};
        
        int i = 0; string ans = "";
        while(i < 10)
        {
            pair<char,pair<string,int>> tp = word[i];
            char ch = tp.first;
            if(alphabet[ch-'a'] == 0)
            {
                i++;
                continue;
            }
            string str = tp.second.first;
            int num = tp.second.second;
            for(int j = 0; j < str.size(); j++)
            {
                alphabet[str[j]-'a']--;
            }
            ans += to_string(num);
        }
        vector<int> srt(10,0);
        for(char &val : ans)
        {
            srt[val-'0']++;
        }
        ans = "";
        for(int k = 0; k < 10; k++)
        {
            if(srt[k] == 0) continue;
            while(srt[k]--)
                ans += to_string(k);
        }
        return ans;
    }

};