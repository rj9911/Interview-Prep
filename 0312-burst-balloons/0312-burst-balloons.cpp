class Solution {
public:
    int maxCoins(vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("The input vector should not be empty.");
    }
    
    const int n = nums.size();

    std::vector<int> extended_nums = nums;

    extended_nums.push_back(1);
    extended_nums.insert(extended_nums.begin(), 1);
    
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {

            if (i > j) 
               continue;

            int max_coins = 0;

            for (int ind = i; ind <= j; ++ind) {
                int cost = extended_nums[i - 1] * extended_nums[ind] * extended_nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                max_coins = std::max(cost, max_coins);
            }

            dp[i][j] = max_coins;

        }
    }

    return dp[1][n];

    }
};