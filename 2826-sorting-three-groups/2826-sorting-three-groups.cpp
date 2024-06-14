class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(4));
        for (int currIdx = n; currIdx >= 0; currIdx--)
        {
            for (int prevGroup = 1; prevGroup <= 3; prevGroup++)
            {
                if (currIdx == n) 
                {
                    dp[currIdx][prevGroup] = 0; //base case
                    continue;
                }
                //================================================================
                int currGroup = nums[currIdx];
                int minOp = INT_MAX;
                //newGroup should be >= prevGroup
                for (int newGroup = prevGroup; newGroup <= 3; newGroup++) 
                {
                    int nextOp = dp[currIdx + 1][newGroup]; 
                    if (newGroup != currGroup) 
                        nextOp++;   //1 operation for changing the group of currIdx

                    minOp = min(minOp, nextOp);
                }                
                //====================================================================
                dp[currIdx][prevGroup] = minOp;
            }
        }
        return dp[0][1];
    }

};