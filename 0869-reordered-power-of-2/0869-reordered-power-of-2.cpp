class Solution {
public:
    bool reorderedPowerOf2(int n) { 

         int x = pow(10 , 9);
         map<int ,vector<int>>word;
         for(int i=1;i<=x;i=i*2){
             int k =i;
             vector<int>v(10 , 0);
             while(k){
                 int l = k%10;
                 v[l]++;
                 k=k/10;
             }
             word[i]=v;
         }
        
         vector<int> v(10 , 0);
         while(n){
             int l = n%10;
             v[l]++;
             n=n/10;
         }
        
         for(int i=1;i<=x;i=i*2){
            
             vector<int> m=word[i];
             bool flag=0;
             for(int j=0;j<=9;j++){
                if(v[j]!=m[j]){
                    flag=1;
                }
             }
             if(flag==0){
                 return 1;
             }
         }
         return 0; 
    }

};