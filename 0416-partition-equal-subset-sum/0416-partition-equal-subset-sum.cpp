class Solution {
public:

bool canPartition(std::vector<int>& nums) {
    int N = nums.size();
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += nums[i];
    }

    if (sum % 2 != 0) {
        return false;
    }

    int target = sum / 2;
    std::vector<std::vector<bool>> t(N + 1, std::vector<bool>(target + 1, false));

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= target; j++) {
            if (i == 0) {
                t[i][j] = false;
            }
            if (j == 0) {
                t[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= target; j++) {
            if (nums[i - 1] <= j) {
                t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[N][target];
}

};