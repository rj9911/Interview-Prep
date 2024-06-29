class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
          int completesubcount=0;

          for(int p=1;p<=26;p++){
              int subsize=p*k;
              int mp[26];
              memset(mp,0,sizeof(mp));
              int j=0; 
              int uniquecount=0;
              //looping for all possible strings that can be unique if subsize<=word.size()
              if(subsize<=word.size()){
              for(int i=0;i<word.size();i++){
                  if(i and abs(word[i]-word[i-1])>2){
                       memset(mp,0,sizeof(mp));
                       uniquecount=0;
                       j=i;
                   }
                   mp[word[i]-'a']++;
            //here unique count will only be increased if particular char count is k
                   uniquecount+=mp[word[i]-'a']==k;
               //reducing window size if current size exceeds permitted size
                   if(i-j+1>subsize){
                     mp[word[j]-'a']--;
                     uniquecount-=(mp[word[j]-'a']==k-1);
                     j++;
                  }
                    completesubcount+=(uniquecount==p);
              }
            }
        }
          return completesubcount;
    }

};