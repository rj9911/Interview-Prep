class Solution {
public:
    int smallestDistancePair(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int n = v.size();
        int mn = 0, mx = v[n-1]-v[0]+1,mid,ans,x,i,j;
        while(mn <= mx){
            mid = (mx-mn)/2+mn;
            i = 0, j = 0,x=0;
            while(i<n){
                while(v[i]-v[j]>mid){
                    j++;
                }
                x += (i-j);
                i++;
            }
            if(x>=k){
                ans = mid;
                mx = mid-1;
            }else{
                mn = mid+1;
            }

        }
        return ans;
    }

};