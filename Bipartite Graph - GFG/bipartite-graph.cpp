//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   // DFS based Approach using of queue and simply painting the nodes and checking of two adjacent
   // nodes are not of same colour.
   bool checkbipartite(int V, vector<int> adj[], int src, vector<int> &colorvector, bool flag){
    int color = colorvector[src];
    vector<int>v = adj[src]; // Adjacency list
            
    for(int neighbour : v){
        if(colorvector[neighbour]!=-1){ // coloured vertices
            if(colorvector[neighbour] == color){
                flag= false;
                return false;
            } // if parent and neighbour got same color then false
        }else{ // uncolured
            colorvector[neighbour] = (color==0)?1:0;
            if(!checkbipartite(V, adj, neighbour, colorvector, flag)) return false;
        }
    }
    return flag;
}

bool isBipartite(int V, vector<int>adj[]){
    vector<int> colorvector(V,-1);
     
    for(int i=0;i<V;i++){    // Done to make call on every vertices as graph is not connected
        if(colorvector[i] == -1){
            colorvector[i] = 0;
            bool flag = true;
            if(!checkbipartite(V , adj , i, colorvector, flag)) return false;
        }
    }
    return true;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends