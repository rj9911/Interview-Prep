class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> num_reqs;
        sort(ages.begin(), ages.end());
        int cnt = 0;
        int n = ages.size();
        for (int i = n - 1; i >= 0; i--) {
            int age_x = ages[i];
            if (num_reqs.find(age_x) != num_reqs.end()) {
                cnt += num_reqs[age_x];
            } else {
                double factored_age = 0.5 * age_x + 7;
                int cnt_x = 0;
                auto it  = upper_bound(ages.begin(), ages.begin() + i, factored_age);
                if (it == ages.begin() + i) {
                    num_reqs[age_x] = 0;
                } else {
                    int it_idx = distance(ages.begin(), it);
                    cnt_x = (i - it_idx);
                    num_reqs[age_x] = cnt_x;
                    cnt += num_reqs[age_x];
                }

            }
        }
        return cnt;
    }

};