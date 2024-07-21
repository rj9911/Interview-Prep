class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<int> v(26, 0);
        
        for(auto c : s) v[c - 'a']++; // Storing the frequencies of each character
        
        stack<char> st;
        string res = "";
        int i = 0;
        int curr = 0; // Pointer to the current lexicographically lowest char present in the string
        
        while(i < n){
            while(v[curr] == 0) curr++;
            // This is when we encounter higher char when lower char are already present in the stack, we push the in result before current char.
            while(!st.empty() && st.top() <= curr + 'a'){
                res.push_back(st.top());
                st.pop();
            }
            // Found eaxct match, append to result.
            if(s[i] == curr + 'a'){
                res.push_back(s[i]);
                v[curr]--;
            }
            // If not a match, push the char into the stack, decrease the frequency.
            else{
                st.push(s[i]);
                v[s[i] - 'a']--;
            }
            
            i++;
        }
        // If stack is not empty, append remaining characters to result.
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }

};