class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string>s(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({start,0});

        while(!q.empty()){
             string gene=q.front().first;
             int lev=q.front().second;
             q.pop();
             if(gene==end){
                 return lev;
             }
             for(int i=0;i<gene.length();i++){
                 vector<char>mut={'A','C','G','T'};
                char original=gene[i];
                 for(int j=0;j<4;j++){
                   gene[i]=mut[j];
                    if(s.find(gene)!=s.end()){
                        s.erase(gene);
                        q.push({gene,lev+1});
                    }
                 }
                 gene[i]=original;
             }
        }
        
        return -1;
    }

};