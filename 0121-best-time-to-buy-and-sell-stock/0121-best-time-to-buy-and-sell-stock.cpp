class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ls = INT_MAX;
        int op = 0;
        int pr = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < ls){
                ls = prices[i];
            }
            pr = prices[i]-ls;
            if(op < pr){
                op = pr;
            }
        }
        return op;
    }
};