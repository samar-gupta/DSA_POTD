class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        // Building the adjacency list for an unweighted graph
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        
        vector<int> distance(N, INT_MAX);
        distance[src] = 0;
        queue<int> q; q.push(src);
        // BFS for shortest path in an unweighted graph while (!q.empty()) {
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int adjNode: adj[node]) {
                if (distance[node] + 1 < distance[adjNode]) { 
                    distance[adjNode] = distance[node] + 1;
                    q.push(adjNode);
                }
            }
        }
         
        // Replace INT_MAX with -1 if a node is unreachable
        for(int i=0; i<N; i++) {
            if (distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }
    
        return distance;
    }
};
