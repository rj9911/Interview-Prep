class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) 
    {
        sort(stones.begin(),stones.end());
        int n=stones.size();
        int low=n;
        for(int i=0,j=0;j<n;j++)
        {
            while(stones[j]-stones[i]+1>n)
                i++;
            int already_store=j-i+1;
            if(already_store==n-1&&(stones[j]-stones[i]+1==n-1))
            {
                low=min(low,2);
            }
            else
            {
                low=min(low,n-already_store);
            }
        }
        return {low,max(stones[n-1]-stones[1]-n+1,stones[n-2]-stones[0]-n+1)+1};
        
    }

};