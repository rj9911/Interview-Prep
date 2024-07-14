class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) 
    {
        vector<int> ans;
        int n=favoriteCompanies.size();
        vector<unordered_set<string>> fc(n);
        for(int x=0; x<n; x++)
        {
            for(int y=0; y<favoriteCompanies[x].size(); y++)
            {
                fc[x].insert(favoriteCompanies[x][y]);
            }
        }
        for(int x=0; x<n; x++)
        {
            int cnt=0;
            vector<string> v1=favoriteCompanies[x];
            for(int y=0; y<n; y++)
            {
                if(x!=y)
                {
                    int f=1;
                    for(int i=0; i<v1.size(); i++)
                    {
                        if(fc[y].find(v1[i])==fc[y].end())
                        {
                            f=0; break;
                        }
                    }
                    if(!f)
                    {
                        cnt++;
                    }
                }
            }
            if(cnt==n-1) ans.push_back(x);
        }
        return ans;
    }

};