class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int taskSize = tasks.size();
        vector<bool> ok(1<<taskSize, false);

        for(int mask=1;mask < (1<<taskSize); mask++){
            int remainTime = sessionTime;
            for(int j = 0; j < taskSize; j++){
                if( (1<<j) & mask) {
                    remainTime -= tasks[j];
                }
            }
            if(remainTime >= 0){
                ok[mask] = true;
            }   
        }

        vector<int> dp(1<<taskSize, INT_MAX);
        dp[0] = 0;

        for(int mask=1; mask < (1<<taskSize); mask++){
            
            for(int j = mask; j > 0; j=(j-1) & mask ){
                if(ok[j] == true){
                    dp[mask] = min(dp[mask], dp[mask ^ j] + 1);
                }
            }
        }

        return dp[(1<<taskSize) -1];
    }

};