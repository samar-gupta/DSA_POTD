class Solution {
  public:
    void dfsHelper(int vertex, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        // Mark current vertex as visited and add to result
        visited[vertex] = true;
        result.push_back(vertex);
        
        // Visit all neighbors in the order they appear in adjacency list
        for(int neighbor : adj[vertex]) {
            if(!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
        
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> result;           // To store the DFS traversal
        vector<bool> visited(adj.size(), false);  // To track visited vertices
        
        // Start DFS from vertex 0
        dfsHelper(0, adj, visited, result);
        return result;
    }
};
