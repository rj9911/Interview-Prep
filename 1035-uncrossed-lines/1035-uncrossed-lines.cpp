class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int nums1Start = n1 - 1; nums1Start >= 0; nums1Start--)
        {
            for (int nums2Start = n2 - 1; nums2Start >= 0; nums2Start--)
            {
                //======================================================================================
                int makeLineCount = 0, notMakeLineCount = 0;
                if (nums1[nums1Start] == nums2[nums2Start]) 
                    makeLineCount = 1 + dp[nums1Start + 1][nums2Start + 1]; 
                else
                {
                    int leaveFromNums1 = dp[nums1Start + 1][nums2Start];
                    int leaveFromNums2 = dp[nums1Start][nums2Start + 1];
                    notMakeLineCount = max(leaveFromNums1, leaveFromNums2);
                }
                //=======================================================================================
                dp[nums1Start][nums2Start] = max(makeLineCount, notMakeLineCount);
            }
        }
        int ans = dp[0][0];
        return ans;
    }

};