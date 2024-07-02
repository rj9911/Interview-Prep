class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> pa,pb;
        int n = s.length();
        for(int i = 0; i<=n-a.length(); i++){
            if(a.length()>s.length()) break;
            string x = "";
            x = s.substr(i,a.length());
            if(x == a){
                pa.push_back(i);
            }
            
        }
        for(int i = 0; i<=n-b.length(); i++){
            if(b.length()>s.length()) break;
            string x = "";
            x = s.substr(i,b.length());
            if(x == b){
                pb.push_back(i);
            }
        }
        
        vector<int> ans;
        int i = 0,j = 0;
        while(i<pa.size() && j<pb.size()){
            if(abs(pa[i]-pb[j]) <= k) ans.push_back(pa[i]),i++;
            else if(pa[i]<pb[j]) i++;
            else j++;
        }
        
        return ans;
    }

};