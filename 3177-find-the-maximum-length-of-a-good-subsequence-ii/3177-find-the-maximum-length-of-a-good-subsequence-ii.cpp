class Solution {
public:
    int maximumLength(vector<int>& A, int M) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        map<int, int> last;
        int N = A.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1));
        vector<int> best(M + 1);
        for(int i = 0 ; i < N ; ++i) {
            int ind = last[A[i]];
            for(int j = 0 ; j <= M ; ++j) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[ind][j] + 1);
                if(j)
                    dp[i + 1][j] = max(dp[i + 1][j], best[j - 1] + 1);
            }
            for(int j = 0 ; j <= M ; ++j) {
                best[j] = max(best[j], dp[i + 1][j]);
            }
            last[A[i]] = i + 1;
        }
        return best[M];
    }

};