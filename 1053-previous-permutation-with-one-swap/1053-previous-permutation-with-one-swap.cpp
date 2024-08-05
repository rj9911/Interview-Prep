class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        stack<pair<int, int>> stk;
        
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int idx = -1;
            int prev = -1;
            while (!stk.empty() && stk.top().first < arr[i])
            {
                if (stk.top().first == prev)
                {
                    stk.pop();
                    continue;
                }
                idx = stk.top().second;
                prev = stk.top().first;
                stk.pop();
            }
            if (idx != -1)
            {
                swap(arr[i], arr[idx]);
                return arr;
            }
            stk.push({arr[i], i});
        }
        
        return arr;
    }

};