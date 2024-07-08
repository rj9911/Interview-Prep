class Solution {
public:
    int maximumTastiness(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int n = v.size();
        int mn = 0, mx = v[n-1],mid,i,j,x,ans;
        while(mn <= mx){
            mid = (mx-mn)/2+mn;
            i = 0, j = 0, x = 1;
            for(i = 0; i < n; i++){
                if(v[i]-v[j]>=mid){
                    x++;
                    j = i;
                }
            }
            if(x>=k){
                ans = mid;
                mn = mid+1;
            }else{
                mx = mid-1;
            }
        }
        return ans;
    }

};