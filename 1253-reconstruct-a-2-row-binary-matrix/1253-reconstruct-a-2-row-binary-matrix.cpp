class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans( 2 , vector<int> (n, 0)) ;
        vector<vector<int>> x;
        int i;
        for(i = 0 ; i<colsum.size();i++)
        {
            if(colsum[i]==2 && upper>=1 && lower>=1)
            {
                ans[0][i] = ans[1][i] = 1 ;
                upper--;
                lower-- ;
            }
            else if(colsum[i]==1 && upper>=1 && upper>=lower)
            {
                ans[0][i] = 1 ;
                ans[1][i] = 0 ;
                upper-- ;
            }
            else if(colsum[i]==1 && lower>=1 && upper<lower)
            {
                ans[1][i] = 1 ;
                ans[0][i] = 0 ;
                lower-- ;
            }
            else if(colsum[i]==0)
                ans[0][i] = ans[1][i] = 0 ;
            else return x ;
        }
        if(lower==0 && upper==0)
        return ans;
        else
        return x ;
    }

};