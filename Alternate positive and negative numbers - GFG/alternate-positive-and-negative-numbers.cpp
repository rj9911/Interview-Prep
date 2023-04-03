//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int a[], int n) {
	    vector<int> ap,an;
	    
	    for(int i=0;i<n;i++){
	        if(a[i] < 0) an.push_back(a[i]);
	        else ap.push_back(a[i]);
	    }
	    int i=0,j=0,k=0;
	    while(i<n){
	        if(j<ap.size()){
	            a[i++] = ap[j++];  
	        }
	        if(k<an.size()){
	            a[i++] = an[k++];
	        }
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends