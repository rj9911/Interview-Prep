class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        vector<int> stack;
        int res = 0;

        stack.push_back(target[0]);
        for (int i = 1; i < target.size(); i++) {
            if (target[i] > stack.back()) {
                stack.push_back(target[i]);
                continue;
            } 
            if (target[i] == stack.back())
                continue;

            int top = stack.back();

            while (!stack.empty() && target[i] < stack.back())
                stack.pop_back();

            res += top - target[i];
            stack.push_back(target[i]);
        }
        
        if (!stack.empty())
            res += stack.back();

        return res;
    }

};