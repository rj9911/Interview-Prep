class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        int n = a.size();
        sort(a.begin(), a.end());
        int end = n-1;
        int res = 0;
        for(int i=0;i<n;i++) {
            if(a[i]<0) continue;
            while(end>=0 && a[end]+a[i]>limit)end--;

            if(end>i &&  a[end]+a[i]<=limit) {
                a[end]=a[end]*-1;
                end--;
            }
            res++;
        }
        return res;
    }

};