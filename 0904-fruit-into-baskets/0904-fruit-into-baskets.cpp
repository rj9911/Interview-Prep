class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m; 
        int start = 0; int c = 0,u = 0,  ma = -1; 

        for(int i=0; i<fruits.size(); i++){
            if(m[fruits[i]] == 0){
                m[fruits[i]]++; c++; u++; 
                if( u > 2){
                    for(int j=start; j<=i; j++){
                        m[fruits[j]]--; c--; 
                        if(m[fruits[j]] == 0) {u--; start = j+1; break; }
                    }
                }
            }
            else {
                m[fruits[i]]++; c++; 
            }

            if(ma < c) ma = c; 
        }

        return ma; 
    }

};