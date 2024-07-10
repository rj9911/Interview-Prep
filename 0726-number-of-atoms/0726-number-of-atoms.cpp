class Solution {
public:
   string countOfAtoms(string A) {
        int n = A.size();
        stack<int> st;
        map<string, int> cnt;
        st.push(1);
        for(int i = n-1; i>=0; i--) {
            int cur = 0;
            int expo = 1;
            string s;
            while(i >= 0 && isdigit(A[i])) {
                cur += expo*(A[i]-'0');
                expo*=10;
                i--;
            }
            if(A[i] == ')') {
                if(cur != 0) st.push(st.top()*cur);
                else st.push(st.top());
            }
            while(i >= 0 && islower(A[i])) {
                s = A[i] + s;
                i--;
            }
            if(isupper(A[i])) s = A[i]+s;
            if(!s.empty()) {
                if(cur != 0) cnt[s] += st.top()*cur;
                else cnt[s] += st.top();
            }
            if(A[i] == '(') {
                st.pop();
            }
        }
        
        
        string ans;
        for(auto x : cnt) {
            //cout << x.first << ' ' << x.second << endl;
            ans += x.first;
            if(x.second > 1) ans += to_string(x.second);
        }
        
        return ans;
    }
};