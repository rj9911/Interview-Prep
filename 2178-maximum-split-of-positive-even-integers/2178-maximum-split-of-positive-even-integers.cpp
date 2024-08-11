class Solution {
public:
vector<long long> maximumEvenSplit(long long n) {   //changed finalSum to n for simplicity 
        vector<long long>v;
        if(n%2!=0){   //Split is not possible for odd finalSum
            return v;
        }
        else{
            long long i=2;
            long long sum=0;
            while(1){
                if((sum+i) > n) break;
                 v.push_back(i); //keep pushing the even numbers starting from 2 and incrementing it by 2
                 sum+=i;
                 i+=2;
            }
            long long dif = n - sum;
            if(dif > 0){
                long long x = v[v.size()-1];  
                x+=dif;
                v.pop_back();   //Pop out last element and push whole remaining difference needed
                v.push_back(x);
            }
            return v;
        }
    }
};