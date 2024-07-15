class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<char>> matrix(m + 1, vector<char>(n + 1, false));
        for (int i = 0; i < m; i++) {
            for (const auto& language : languages[i]) {
                matrix[i + 1][language] = true;
            }
        }
        vector<char> learn(m + 1, false);
        for (const auto& friendship : friendships) {
            bool can_communicate = false;
            for (int i = 1; i <= n; i++) {
                if (matrix[friendship[0]][i] && matrix[friendship[1]][i]) {
                    can_communicate = true;
                    break;
                }
            }
            if (!can_communicate) {
                learn[friendship[0]] = true;
                learn[friendship[1]] = true;
            }
        }
        int minimum_learnings = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int learnings = 0;
            for (int j = 1; j <= m; j++) {
                if (learn[j] && !matrix[j][i]) {
                    learnings++;
                }
            }
            minimum_learnings = min(minimum_learnings, learnings);
        }
        return minimum_learnings;
    }

};