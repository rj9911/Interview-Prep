class Solution {
public:
    int maximumStrongPairXor(vector<int>& A) {
        int res = 0;
        for (int i = 20; i >= 0; --i) {
            res <<= 1;
            unordered_map<int, int> pref, pref2;
            for (int& a : A) {
                int p = a >> i;
                if (pref.find(p) == pref.end())
                    pref[p] = pref2[p] = a;
                pref[p] = min(pref[p], a);
                pref2[p] = max(pref2[p], a);
            }
            for (auto& it: pref) {
                int x = it.first, y = res ^ 1 ^ x;
                if (x >= y && pref.count(y) && pref[x] <= pref2[y] * 2) {
                    res |= 1;
                    break;
                }
            }
        }
        return res;
    }

};