class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int a=-1,b=num.size()-1;
        for(int i=0;i<num.length();i++){
            if(change[num[i]-'0']>num[i]-'0'){
                a=i;
                break;
            }
        }
        if(a==-1)
            return num;
        for(int i=a+1;i<num.length();i++){
            if(change[num[i]-'0']<num[i]-'0'){
                b=i-1;
                break;
            }
        }
        // cout<<a<<" "<<b<<endl;
        for(int i=a;i<=b;i++){
            num[i]=change[num[i]-'0']+'0';
        }
        return num;
    }

};