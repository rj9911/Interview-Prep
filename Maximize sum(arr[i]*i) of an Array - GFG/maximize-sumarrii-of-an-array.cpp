//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n)
    {
       const int MOD = 1000000007;
        int ans=0; //intializing a temporary variable to that we can store the answer
        sort( a , a+n); //sorting the array
        for(int i =0 ; i<n;i++){
            // ans += a[i]*i; //<--can not use this as the answer will overflow
            ans = (ans + ((long long)a[i] * i) % MOD) % MOD;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends