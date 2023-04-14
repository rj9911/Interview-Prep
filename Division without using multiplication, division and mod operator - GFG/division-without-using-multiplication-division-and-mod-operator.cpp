//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    // (57 << 1) -> 1 1 1 0 0 1  -> every 2's in this will be multilied by 2 in this, hence multiplied by 2
    // mulitiplication
    
    // 57 >> 1
    // Here quotient -> 1 1 1 0 0 and remainder -> 1
    // Division
    
    // (57 << 2) -> here every 2's in this will be multiplied by 4. hence whole no. is multiplied by 4

    // 57 >> 2
    // Here quotient -> 1 1 1 0 and remainder -> 0 1
    
    // Overall
    // n << x  => n *(2 ^ x)  (Right shift by 3 hence no. is multiplied by 8)
    // n >> x  => 
    
    public:
    long long divide(long long dividend, long long divisor) 
    {
        long long quotient = 0;
        long long temp = 0;
        long long sign = (dividend >= 0) ^ (divisor >= 0) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        for(int i = 31; i >= 0; i--){
            if(temp + (divisor << i) <= dividend){
                temp += divisor << i;
                quotient += (1LL << i);
            }
        }
        return quotient*sign; 
         
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends