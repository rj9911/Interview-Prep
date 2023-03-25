//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    /* Approach -> DFS Approach
    inorder and visited array taken
    if elem is found in order array then cycle detects else not.
    
    */
    // Function to detect cycle in a directed graph.
    bool solve(int src, vector<int> &vis, vector<int> &order, vector<int> adj[]){
        vis[src] = 1;
        order[src] = 1;
        for(auto x : adj[src]){
            if(!vis[x]){
                bool conf = solve(x, vis, order, adj);
                if(conf == true) 
                  return true;
            }
            else if(order[x]) return true;   // if current node founds in order then cycle detects.
        }
        order[src] = 0;     // Backtracks and removing the node from order array.
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
      vector<int> vis(V, 0);
      vector<int> order(V, 0);
      for(int i=0;i<V;i++){
          if(!vis[i]){
              bool c = solve(i, vis, order, adj);
              if(c == true) 
                return true;
          }
      }
      return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends