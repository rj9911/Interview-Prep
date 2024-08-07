class Solution {
public:
    int maxDiff(int nums) {
        string s = to_string(nums) ;
        string a = s;
        string b = s ;
        
        int i = 0 ;
        while(i < a.size() and a[i] == '9') ++i ;
        if(i < a.size()){
            char replace = a[i] ;
            for(int j = i ; j < a.size() ; ++j) if(a[j] == replace) a[j] = '9' ;
        }
        
        i = 0 ;
        while(i < b.size() and b[i] == '1') ++i ;
        if(i and b[i]  == '0') while(i < b.size() and (b[i] == '0' || b[i] == '1')) ++i ;
        
        if(i < b.size()){
            char fill = '0' ; char replace = b[i] ;
            if(!i) fill = '1' ;
            for(int j = i ; j < b.size() ; ++j) if(b[j] == replace) b[j] = fill ;
        }
        
        return stoi(a) - stoi(b) ;
        
        
    }

};