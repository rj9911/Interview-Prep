//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool issafetoassign(int i, int j,bool graph[101][101] , int V,vector<int> &color){
        // Check if i can assign color j to node i
        // no other neighbouring node of i should have the same color.
        for(int k=0;k<V;k++){
            if(graph[i][k]==1 and color[k]==j) return false;
        }
        return true;
    }
    
    bool fnc(bool graph[101][101], int m, int V, int i, vector<int> &color){
        if(i == V) return true;
        
        for(int j=0;j<m;j++){
            if(issafetoassign(i,j,graph,V, color)){
                color[i] = j;
                
                if(fnc(graph, m, V, i+1,color)) return true;
                
                color[i] = -1; // Backtracks and check for another case of color
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int V) {
        vector<int> color(V, -1);
        
        return fnc(graph, m, V, 0, color);
        
        // assign -> 0 to m
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends