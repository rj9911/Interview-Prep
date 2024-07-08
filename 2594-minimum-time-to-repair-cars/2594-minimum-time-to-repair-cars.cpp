class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long int mn = 0, mx = 1e15, mid = 0;
        long long int ans,k=0;
        while(mn<=mx){
            mid = (mx-mn)/2+mn;
            k = 0;
            for(auto &i: ranks){
                k += sqrt(mid/i);
            }
            if(k>=cars){
                ans = mid;
                mx = mid-1;
            }else{
                mn = mid+1;
            }
        }
        return ans;
    }

};