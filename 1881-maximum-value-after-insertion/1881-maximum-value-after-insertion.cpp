class Solution {
public:
    string maxValue(string n, int x) {
        string s=to_string(x);
        if (n[0]=='-'){
            int i=1;
            while(i<n.size()){
                int digit=n[i]-'0';
                if (digit>x){
                    break;
                }
                i++;
            }
            n=n.substr(0,i)+s+n.substr(i,n.length());
        }
        else{
            int i=0;
            while(i<n.size()){
                int digit=n[i]-'0';
                if (digit<x){
                    break;
                }
                i++;
            }
            n=n.substr(0,i)+s+n.substr(i,n.length());
        }
        return n;
    }

};