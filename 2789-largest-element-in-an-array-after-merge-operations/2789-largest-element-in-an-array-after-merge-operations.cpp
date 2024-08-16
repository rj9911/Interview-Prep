class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        stack<long long> st;
        for(int i = n-1; i >= 0; i--) {
            if(st.empty() || st.top() < nums[i]) {
                st.push(nums[i]);
            } 
            else {
                long long a = st.top();
                st.pop();
                st.push(nums[i] + a);
            }
        }
        long long mx = nums[0];
        while(!st.empty()) {
            mx = max(mx, st.top());
            st.pop();
        }
        return mx;
    }

};