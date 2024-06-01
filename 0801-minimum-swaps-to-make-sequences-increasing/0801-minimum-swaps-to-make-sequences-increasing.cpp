class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for(int i = n-2;i>=0;i--)
        {
            for(int j = 0;j<=1;j++)
            {
                int a = 1e6, b = 1e6;
                if(j==0)
                {
                    if(nums1[i]<nums1[i+1] && nums2[i]<nums2[i+1]) a = dp[i+1][0];
                    if(nums1[i]<nums2[i+1] && nums2[i]<nums1[i+1]) b = 1+dp[i+1][1];
                }
                else
                {
                    if(nums1[i]<nums2[i+1] && nums2[i]<nums1[i+1]) a = dp[i+1][0];
                    if(nums1[i]<nums1[i+1] && nums2[i]<nums2[i+1]) b = 1+dp[i+1][1];
                }
                dp[i][j] = min(a, b);
            }
        }
        return dp[0][0];
    }

};