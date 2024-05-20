class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        
        for(auto a: nums1) res.push_back(a);
        for(auto a: nums2) res.push_back(a);
        
        sort(res.begin(), res.end());
            
        int n = res.size();
        
        if(n%2!=0){
            int idx = n/2;
            return res[idx];
        }else{
            int idx1 = n/2;
            int idx2 = idx1-1;
            
            return (double)(res[idx1]+res[idx2])/2;
        }
        
        return 0.0;
    }
};