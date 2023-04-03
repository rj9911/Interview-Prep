//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int num[], int n)
    {
       unordered_map<int, int>mp;
        int count= 0 ;
        int res = -1;
       for(int i=0;i< n; i++){
           mp[num[i]]++;
       } 
        for(int i = 0 ; i < n ; i++){
          if(mp[num[i]] > n/2){
              res = num[i];
              break;
          }
        }
        return res;
      /*  Time -> O(n)
        Space -> O(n/2) => O(n)
        No. of Majority elem = 1
        Other elems = n/2 - 1
        1 + n/2 - 1 = n/2
        sort(nums.begin() , nums.end());
        return nums[n/2];
        // Time -> O(nlogn)
        // Space -> O(1) */
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends