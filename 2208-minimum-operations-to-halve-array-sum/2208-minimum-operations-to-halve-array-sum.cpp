class Solution {
public:
    int halveArray(vector<int>& nums) {
        double cur_sum = 0;
        for (auto x: nums)
            cur_sum += x;
        double original_sum = cur_sum;
        priority_queue<double> help;
        for(auto x: nums)
            help.push(x);
        
        long long ans = 0;
        
        while((original_sum - cur_sum)<(original_sum)/2){
            ans += 1;
            double temp = help.top();
            help.pop();
            cur_sum -= temp;
            cur_sum += (temp)/2;
            help.push((temp)/2);
            
        }
        return ans;
    }

};