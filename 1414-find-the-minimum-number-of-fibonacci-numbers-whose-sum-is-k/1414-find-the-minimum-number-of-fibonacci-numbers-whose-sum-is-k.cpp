class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if(k == 1 || k == 2) return 1;

        vector<int> dp {1,1};

        int num = 2;
        while(num <= k){
            dp.push_back(num);

            int a = dp.back();
            int b = dp[dp.size()-2];

            num = a + b;
        }

        int cnt = 0, i = dp.size()-1;
        while(k > 0){
            while(i >= 0 && dp[i] > k){
                i--;
            }

            k = k - dp[i];
            cnt++;
        }

        return cnt;
    }

};