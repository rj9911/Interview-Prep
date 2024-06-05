class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph = vector<vector<int>>(n, vector(n, INT_MAX));
        // Adding the weights to the graph
        for (vector<int> e: edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }

        // Performing floyd-warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][k] >= INT_MAX || graph[k][j] >= INT_MAX)
                        continue;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        // Finding the city with smallest number of neighbours <= distThreshold
        int smallestCity = -1;
        int smallestNumber = INT_MAX;
        // From the back to satisfy equal num return larger city
        for (int i = n-1; i > -1; i--) {
            int target = 0;
            for (int j = 0; j < n; j++) {
                if (graph[i][j] <= distanceThreshold && i != j) {
                    target++;
                }
            }
            if (target < smallestNumber) {
                smallestNumber = target;
                smallestCity = i;
            }
        }
        return smallestCity;
    }

};