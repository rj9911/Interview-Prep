//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   // BFS based Approach using of queue and simply painting the nodes and checking of two adjacent
   // nodes are not of same colour.
    bool checkbipartite(int V, vector<int> adj[], int src,  vector<int> &colorvector){
        queue<int> q;
        q.push(src);
        colorvector[src] = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int color = colorvector[x];
            vector<int>v = adj[x];
            
            for(int neighbour : v){
                if(colorvector[neighbour]!=-1){
                    if(colorvector[neighbour] == color) return false;
                }else // uncoloured
                {
                    colorvector[neighbour] = (color==0)?1:0;
                    q.push(neighbour);
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int> colorvector(V,-1);
	   for(int i=0;i<V;i++){
	       if(colorvector[i] == -1){
	           if(checkbipartite(V , adj , i, colorvector) == false) return false;
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