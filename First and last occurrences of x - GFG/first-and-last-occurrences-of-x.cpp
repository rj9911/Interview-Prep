//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int x )
{
      vector<int> v;
        for(int i=0;i<n;i++){
          if(nums[i] == x){ 
              v.push_back(i);
              break;
          }
        }
        for(int i=n-1;i>=0;i--){
          if(nums[i] == x){ 
              v.push_back(i);
              break;
          }
        }
        if(v.size() == 0) return {-1,-1};
        return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends