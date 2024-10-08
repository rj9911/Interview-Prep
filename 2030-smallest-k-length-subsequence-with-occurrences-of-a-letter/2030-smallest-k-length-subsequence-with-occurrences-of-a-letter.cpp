class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
         int cnt = count(s.begin(),s.end(),letter) , n = s.size();
         string stk , ans;
         for(int i=0; i<s.size(); i++) {
             // can we remove a big char , check enough elements are left in the array to make length atleast equal to k , also check cnt > repetition
             while(!stk.empty() && cnt>repetition && stk.back() > s[i] && stk.size() + (n - i) > k) {
                 if(letter == stk.back()) cnt--;
                 stk.pop_back();
             }
             // remove big char if they aren't 'letter' when repetition is still satisfied!
             while(!stk.empty() && stk.back()!=letter && stk.back() > s[i] && stk.size() + (n - i) > k && cnt == repetition) stk.pop_back();
             stk.push_back(s[i]);
         }
        for(int i=0; ans.size()<k; i++) {
		     // don't pick any  unnecessary char if required repetition & exact size are not satisfied!
             if(stk[i]!=letter && ans.size() + max(0,repetition) >=k) continue; 
             ans+=stk[i];
             repetition-=letter==stk[i];
        }
        return ans;
    }

};