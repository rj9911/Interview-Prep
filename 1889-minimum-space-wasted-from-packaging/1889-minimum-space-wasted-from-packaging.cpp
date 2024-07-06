class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        int n = packages.size();
        int m = boxes.size();
        
        // Sort the packages array in non-decreasing order
        sort(packages.begin(), packages.end());
        
        // Calculate the prefix sum of the packages array
        vector<long long> prefixSum(n + 1);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + packages[i - 1];
        }
        
        long long minWaste = LLONG_MAX;
        
        for (int i = 0; i < m; i++) {
            // Sort the box sizes in non-decreasing order for each supplier
            sort(boxes[i].begin(), boxes[i].end());
            
            // Skip the supplier if the largest box size is smaller than the largest package size
            if (boxes[i].back() < packages.back()) {
                continue;
            }
            
            long long currWaste = 0;
            int j = 0;
            
            for (int boxSize : boxes[i]) {
                // Find the index of the largest package that can fit in the current box
                int k = upper_bound(packages.begin(), packages.end(), boxSize) - packages.begin() - 1;
                
                // Calculate the wasted space for the packages that fit in the current box
                currWaste += (long long)(k - j + 1) * boxSize - (prefixSum[k + 1] - prefixSum[j]);
                
                j = k + 1;
            }
            
            minWaste = min(minWaste, currWaste);
        }
        
        if (minWaste == LLONG_MAX) {
            return -1;
        }
        
        return minWaste % 1000000007;
    }

};