class Solution {
public:
    int minCharacters(string a, string b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n=a.size(),m=b.size();
        vector<int>prefa(26),prefb(26),sufa(26),sufb(26);
        vector<int>arr(26),brr(26);
        for(int i=0;i<a.size();i++){
            arr[a[i]-'a']++;
        }
        for(int i=0;i<b.size();i++){
            brr[b[i]-'a']++;
        }
        int cnt=INT_MAX;
        //calculating for third condition
        for(int i=0;i<26;i++){
            cnt=min(cnt,n+m-arr[i]-brr[i]);
        }
        //now, for second and third
        prefa[0]=arr[0];
        prefb[0]=brr[0];
        for(int i=1;i<26;i++){
            prefa[i]=prefa[i-1]+arr[i];
            prefb[i]=prefb[i-1]+brr[i];
        }
        sufa[25]=arr[25];
        sufb[25]=brr[25];
        for(int i=24;i>=0;i--){
            sufa[i]=arr[i]+sufa[i+1];
            sufb[i]=brr[i]+sufb[i+1];
        }
        //moving b to the right, i.e., b>a
        for(int i=25;i>=1;i--){
            cnt=min(cnt,prefb[i-1]+sufa[i]);
        }
        //moving a to the right, i.e., a>b;
        for(int i=25;i>=1;i--){
            cnt=min(cnt,prefa[i-1]+sufb[i]);
        }
        return cnt;
    }

};