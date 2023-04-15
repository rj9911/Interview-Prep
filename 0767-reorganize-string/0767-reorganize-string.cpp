class Solution {
public:
    // https://leetcode.com/problems/reorganize-string/discuss/2439149/C%2B%2B-oror-Explained-Intuition-Algo-Code-oror-Not-that-easy
    string reorganizeString(string s) {
            unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++){  m[s[i]]++;  }
        
        for(auto it: m){
            if(it.second > (int)ceil(1.0*s.length()/2) ){
                return ""; // Edge Case
            }
        }
        
        priority_queue< pair<int, char>, vector<pair<int, char>> > pq;
        for(auto it: m){   pq.push({it.second, it.first});   }
        
        string ans="";
        while(!pq.empty()){
            
            char c1=pq.top().second; int n1=pq.top().first; n1--; pq.pop();
            if(pq.size()>0){
                char c2=pq.top().second; int n2=pq.top().first; n2--; pq.pop();
                ans.push_back(c1); ans.push_back(c2);
                
                if(n1>0){   pq.push({n1, c1});   }
                if(n2>0){   pq.push({n2, c2});   }
            }
            else{
                ans.push_back(c1);
                if(n1>0){   pq.push({n1, c1});   }
            } 
        }
        return ans;
    }
};