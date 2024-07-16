class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > 6*n2 || n2 > 6*n1) //cases when we cannot make both arrays equal
         return -1;

        //Step 1 : sort both the arrays
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        //Step 2 : calculate sum of both arrays
        int sum1 = 0, sum2 = 0;
        for(auto it : nums1) {
            sum1 += it;
        }
        for(auto it : nums2) {
            sum2 += it;
        }
     
        //Step 3 : greedily iterate larger sum and smaller sum arrays to get minimum operations
        int diff = abs(sum1 - sum2);
        vector<int> large = (sum1 > sum2) ? nums1 : nums2;
        vector<int> small = (sum1 < sum2) ? nums1 : nums2;

        int i=0, j = large.size()-1, ans = 0;
        while(diff > 0 && i<small.size() && j >= 0)
        {
            ans++; 
            if(6-small[i] > large[j]-1) { //if incrementing smaller array value to 6 gives greater value
                diff -= (6-small[i]); //decrement diff by that amount
                i++;
            }
            else { //otherwise, decrement diff by amount equal to (gap between larger array value and 1)
                diff -= (large[j]-1);
                j--;
            } 
        }
         //if we reach here, either diff has become equal to 0
         //or one of the 2 arrays have been fully traversed

        //if diff is not 0, then exactly one of the following 2 loop will have to run
        while(diff > 0 && i < small.size()) {
            ans++;
            diff -= (6-small[i]);
            i++;
        }
        while(diff > 0 && j >= 0) {
            ans++;
            diff -= (large[j]-1);
            j--;
        }
     return ans; 
    }

};