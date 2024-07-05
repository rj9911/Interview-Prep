class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
    {
        int q=queries.size(), w=words.size();
        vector<int> ans(q,0);
        vector<int> fq(q), fw(w);
        for(int x=0; x<q; x++)
        {
            map<char,int> m;
            for(int y=0; y<queries[x].size(); y++)
            {
                m[queries[x][y]]++;
            }
            fq[x]=m.begin()->second;
        }
        for(int x=0; x<w; x++)
        {
            map<char,int> m;
            for(int y=0; y<words[x].size(); y++)
            {
                m[words[x][y]]++;
            }
            fw[x]=m.begin()->second;
        }
        for(int x=0; x<q; x++)
        {
            for(int y=0; y<w; y++)
            {
                if(fq[x]<fw[y]) ans[x]++;
            }
        }
        return ans;
    }

};