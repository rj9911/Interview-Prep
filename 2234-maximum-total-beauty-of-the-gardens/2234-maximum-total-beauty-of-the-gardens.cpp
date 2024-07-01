#define ll long long 

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());
        vector<ll> dp(n, 0);   

        // Calculate the cumulative difference of beauty values
        //how much flowers needed to make all j equal to i and j<i;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] + (flowers[i] - flowers[i-1]) * i;
        }

        //atleast this any full garden will be there no matter what
        int j = lower_bound(flowers.begin(), flowers.end(), target) - flowers.begin();

        if (j == 0) {
            return n * 1ll * full;
        }

        ll count = newFlowers;
        ll ans = 0;

        while (count > 0 && j >= 0) {
            int i = upper_bound(dp.begin(), dp.end(), count) - dp.begin();

            if (i == 0) {
                break;
            }

            if (i > j) {
                if (j == 0) {
                    ans = max(ans, (n - j) * 1ll * full);
                } else {
                    ll temp = count - dp[j-1];
                    ll mini = (temp / j) + flowers[j-1];
                    ans = max(ans, min(mini, 1ll * target - 1) * 1ll * partial + ((n - j) * 1ll * full));
                }
            } else {
                ll temp = count - dp[i-1];
                ll mini = (temp / i) + flowers[i-1];
                ans = max(ans, min(mini, 1ll * target - 1) * 1ll * partial + (n - j) * 1ll * full);
            }

            if (j - 1 >= 0) {
                count -= target - flowers[j-1];
            }

            // cout << "upper " << j << " " << "lower " << i << " " << ans << " " << count << "\n";
            j--;
        }

        return ans;
    }
};