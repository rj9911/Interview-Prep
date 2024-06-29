class Solution {
public:
    vector<int> pancakeSort(vector<int>& nums) {
    std::vector<int> nums_copy = nums; // Make a copy of nums to sort
    int n = nums_copy.size();
    int j = n - 1;
    std::vector<int> res;
    while (j >= 0) {
        std::priority_queue<std::pair<int, int>> pq;
        for (int i = j; i >= 0; i--) {
            pq.push({nums_copy[i], i});
        }
        std::pair<int, int> it = pq.top();
        if (it.second != j) {
            std::reverse(nums_copy.begin(), nums_copy.begin() + (it.second + 1));
            res.push_back(it.second + 1);
            std::reverse(nums_copy.begin(), nums_copy.begin() + j + 1);
            res.push_back(j + 1);
        }
        j--;
    }
    return res;
    }

};