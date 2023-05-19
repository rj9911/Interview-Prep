class Solution {
public:
    bool dfs(int curr_node,int curr_color,unordered_map<int,vector<int>> &adj,vector<int> &color){
      if(color[curr_node]!=-1) return true;

       color[curr_node] = curr_color;
       for(auto &v : adj[curr_node]){
           if(color[v]==color[curr_node])return false;
           else if(color[v]==-1){
               int color_v = 1-color[curr_node];
               if(dfs(v,color_v,adj,color)==false){
                   return false;
               }
           }
       }
       return true; 
    }

     bool isBipartite(vector<vector<int>>& graph) {
         int V =  graph.size();

         unordered_map<int,vector<int>> adj;
         for(int i=0;i<graph.size();i++){
             for(int j=0;j<graph[i].size();j++){
                 int v = graph[i][j];

                 adj[i].push_back(v);
             }
         }

         vector<int> color(V,-1);
         for(int i=0;i<V;i++){
             if(color[i]==-1){
                 if(dfs(i,0,adj,color)==false){
                     return false;
                 }
             }
         }
         return true;
     }
};