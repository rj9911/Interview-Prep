class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int i = 0; 
        int j = 0;
        int m = word1.length();
        int n = word2.length();        
        while(i < m&& j < n){
            if(word1[i] > word2[j]){
                merge += word1[i++];
            }else if(word1[i] < word2[j]){
                merge += word2[j++];
            }else{
                string s1 = word1.substr(i);
                string s2 = word2.substr(j);
                if(s1 > s2){
                    merge += word1[i++];
                }else{
                    merge  += word2[j++];
                }
        }}       
        while(i < m){
            merge += word1[i++];
        }        
         while(j < n){
            merge += word2[j++];
        }
        return merge;        
    }

};