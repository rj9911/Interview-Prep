class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) 
    {
        int n=s.size();
        if(n==1)return 1;
        int i=0;
        int j=1;
        int cnt=0;
        int maxi=0;
        while(j<n)
        {
            if(s[j]==s[j-1])cnt++;
         
            if(cnt>1)
            {
                maxi=max(maxi,j-i);
             
                i++;
                while(s[i]!=s[i-1]&&i<n)i++;
                
                cnt--;
                
            }
            j++;
          
        }
 
        maxi=max(maxi,j-i);
        return maxi;
        
    }

};