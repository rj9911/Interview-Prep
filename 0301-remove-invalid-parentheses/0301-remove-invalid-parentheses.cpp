class Solution {
public:
    vector<string> ans ;
    unordered_set<string> checked ;
public:
	// returns the count of brackets needs to be deleted : 
    int rem(string s){
        vector<int> stk ;
        for(int i=0; i < s.size() ; i++){
            if(s[i]=='(')
                stk.push_back(i);
            else if (s[i]==')'){
                if(stk.size()>0 && s[stk.back()]=='(')
                    stk.pop_back() ;
                else stk.push_back(i) ;
            } 
        }
        return (int) stk.size() ;
    }
	// checks if the string passed is valid : valid if to be deleted element is zero 
    bool isVal(string s){
        return rem(s) == 0 ; 
    }
    void solve(string s, int del){
		// Base case : if elements to be deleted is zero :
        if(del == 0){
			// if valid string push it to ans vector ;
            if(isVal(s)) ans.push_back(s) ;
            return ;
        }
		//  generate all possible string by deleting one element(bracket)
        for(int i=0; i < s.size(); i++){
            if(s[i]=='(' or s[i]==')'){
                string pre = s.substr(0,i) ;
                string suff = s.substr(i+1) ;
                string temp = pre + suff ;
				// if already checked for current string dont check again 
                if(checked.find(temp) == checked.end()){
                    checked.insert(temp) ;
                    solve(temp, del-1) ;    
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int del = rem(s) ;
        if(del==0) {
            vector<string> res ;
            res.push_back(s) ;
            return res ;
        }
        solve(s, del) ;
        return ans ;
    }
};