class Solution {
public:
std::vector<long long> minOperations(const std::vector<int>& nums, const std::vector<int>& queries) {
    int n = nums.size();
    int m = queries.size();
    
    std::vector<long long> result;
    
    std::vector<int> sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    
    std::vector<long long> arr1(n);
    std::vector<long long> arr2(n);
    
    arr1[0] = sorted_nums[0];
    for(int i = 1; i < n; ++i) {
        arr1[i] = arr1[i - 1] + sorted_nums[i];
    }
    
    arr2[n - 1] = sorted_nums[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        arr2[i] = arr2[i + 1] + sorted_nums[i];
    }
    
    for(int query : queries) {
        long long sum = 0;
        int s = 0, e = n - 1;
        
        while(s <= e) {
            int mid = s + (e - s) / 2;
            
            if(sorted_nums[mid] <= query) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        if(s > 0) {
            sum += static_cast<long long>(query) * s - arr1[s - 1];
        }
        
        if(s < n) {
            sum += arr2[s] - static_cast<long long>(n - s) * query;
        }
        
        result.push_back(sum);
    }
    
    return result;
}

};