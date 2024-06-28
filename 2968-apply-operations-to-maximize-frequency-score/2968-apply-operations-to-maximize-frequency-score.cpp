class Solution {
public:
    int maxFrequencyScore(vector<int>& a, long long k) 
    {
        sort(a.begin(), a.end());
        int l = 0, r = a.size(), ans = 1;
        vector <long long> pre(a.size());
        pre[0] = a[0];
        for (int i = 1; i < a.size(); i++) pre[i] = pre[i-1] + a[i];
        
        while(l <= r)
        {
            int mid = (l+r)/2; 
            long long sm = 0;
            bool ok = false;
            for (int i = 0, j = 0; i < a.size(); i++)
            {
                sm += a[i];
                if (i-j+1 == mid)
                {
                    int m = (i+j)/2;
                    
                    long long x = pre[m]-pre[j]+a[j], xl = (m-j)+1;
                    long long y = pre[i]-pre[m]+a[m], yl = (i-m)+1;
                    
                    long long p = abs(x-a[m]*xl) + abs(y-a[m]*yl);
                    if (p <= k) {
                        ok = true; break;
                    }
                    j++;
                }
            }
            if (ok) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }

};