//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
/* Create Graph 
   Detect Cycle in directed graph using Topological Sort.
*/
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[n];
	    for(auto i: prerequisites){
	        adj[i.first].push_back(i.second);
	    }
	    vector<int>indegree(n);
	    for(int i=0;i<n;i++) {
	        for(auto j: adj[i])
	            indegree[j]++;
	    }
	    queue<int>q;
	    for(int i=0;i<n;i++) {
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    int count = 0;
	    while(!q.empty()) {
	        auto p = q.front();
	        q.pop();
	        count++;
	        for(auto i: adj[p]) {
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	    return count == n;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends