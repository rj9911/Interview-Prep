class Solution {
public:
    bool check(vector<int>& v, int mid, int k) {
        int n = v.size();
        int stores = 0;
        for (int i = 0; i < n; i++) {
            stores += (v[i] + mid - 1) / mid; 
        }
        return stores <= k;
    }

    int minimizedMaximum(int k, vector<int>& v) {
        int n = v.size();
        int s = 1;
        int e = *max_element(v.begin(), v.end()); 
        int ans = e;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (check(v, mid, k)) {
                ans = mid;
                e = mid - 1; 
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};