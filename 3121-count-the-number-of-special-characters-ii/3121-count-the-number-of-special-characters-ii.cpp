class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        unordered_map<int,int>lowpos;
        unordered_map<int,int>highpos;
        unordered_set<int>low;
        for(int i=0;i<word.size();i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                int a = word[i]-'a';
                low.insert(a);
                mp1[a]++;
                lowpos[a] = i;
       
            }
            else{
                int b = word[i]-'A'+'a';
                mp2[b]++;
                if(highpos.find(b) == highpos.end()){
                    highpos[b] = i;
                }
            }
        }
        int ans = 0;
        for(auto i:low){
            int x = i;
            if(mp2.find(x+97) != mp2.end() && lowpos[x] < highpos[x+97]){
                ans = ans+1;
            }
        }
        return ans;
    }

};