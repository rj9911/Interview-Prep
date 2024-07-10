class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {

        long long ans = 0 , n = nums.size();
        vector<int>pref(31,-1);

        for( int i = 0 ; i < n ; i++ )
        {

           int l = 0 , r = i;

           for( int  bits = 30 ; bits >= 0 ; bits-- )
           {
               int p = ( 1 << bits );

               if( p & nums[i] )
               pref[bits] = pref[bits] == -1  ? i : pref[bits] ;
               else
               pref[bits] = -1; 

              int position_set_the_bit = pref[bits]; 
              if( p & k )
              {
                if( position_set_the_bit == -1 || l == -1 )
                l = -1;
                else
                l = max(l,position_set_the_bit);
              }
              else
              {
                if( position_set_the_bit != -1 )
                r = min(r,position_set_the_bit-1);
              }
               
           }

           if( l == -1 || r == -1 ||  l > r )
           continue;

           ans += (r-l+1); 

        }
        return ans;
    }

};