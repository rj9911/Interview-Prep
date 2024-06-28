class Solution {
public:
    long long continuousSubarrays(vector<int>& arr) {
         int n = arr.size();
        if( n == 1) return 1;
        long long ans =n;
        int mx = arr[0] ,mn=arr[0] ;
        for( int i = 0, j =1;  j < n; j++){
            mx = max( arr[j],mx);    // tracking curr max and min val of cur subarray
            mn = min( arr[j],mn);
            if( abs( mx - mn) > 2){   //  diff is more than 2
                int ind = j; 
                int tempmx = arr[j], tempmn= arr[j]; // define tempmx and tempmn to store the max and min element of subarray ind + 1 to j
                while( ind >= i  ){   // iterate upto i
                    if( abs(arr[ind] -arr[j] ) > 2){
                        i = ind +1;                  // as we find the position at which diff greater than 2 , so updating i and stop iteration 
                        break;  
                    }
                    tempmx = max( tempmx, arr[ind]);  
                    tempmn = min( tempmn, arr[ind]);
                    ind--;
                }
                mx = tempmx;  // as we update our subarray [ind +1 to j] so we also update our cur mx and min element 
                mn = tempmn;
                
            }
            ans += j - i;  // adding no of subarray having diff <=2
            
        }
      return ans;
       
    }

};