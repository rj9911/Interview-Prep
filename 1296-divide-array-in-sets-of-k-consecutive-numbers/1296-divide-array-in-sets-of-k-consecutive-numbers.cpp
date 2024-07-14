class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int num : nums) {
            while (!pq.empty() && (pq.top().first < num - 1 || pq.top().second == k)) {
                if (pq.top().second != k) {
                    return false;
                }
                
                pq.pop();
            }
            
            if (pq.empty() || pq.top().first == num) {
                pq.push(make_pair(num, 1));
                continue;
            }
            
            int size = pq.top().second + 1;
            pq.pop();
            pq.push(make_pair(num, size));
        }
        
        while (!pq.empty()) {
            if (pq.top().second != k) {
                return false;
            }

            pq.pop();
        }
        
        return true;
    }

};