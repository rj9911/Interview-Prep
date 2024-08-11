class Solution {
public:
    long long minimalKSum(vector<int>& arr, int k) {
        int i=0;
         
        // Sort the given array
         sort(arr.begin(),arr.end());
         set<int> st;
        //Insert array values in set for remove duplicate values
         for(int i=0;i<arr.size();i++)
            st.insert(arr[i]);
         //Store k in n vriable an increase it untill (value of set <  n)
            long long  n = k; 
            for(auto it : st){
             if(it <= n ){
                 n++;
             }else{
                 break;
             }
         }
        //Then find the sum of n numbers using (n*n+1)/2 formula 
         long long  ans = (n*(n+1))/2;
        //Then remove all those integer value which is less than n and store in set;
         for(auto it: st){
             if(it <= n){
                 ans -= it;
             }
         }
    //Return sum
     return ans;
    }
};