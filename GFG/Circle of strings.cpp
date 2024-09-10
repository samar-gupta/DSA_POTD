class Solution {
  public:    
      
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = 1;
        for(auto v : adj[node]) {
            if(!vis[v]) {
                dfs(v, vis, adj);
            }
        } 
    }
  
    int isCircle(vector<string> &arr) {
        // code here
        vector<vector<int>> adj(26);
        vector<int> vis(26,0);
        
        int start;
        for(auto it: arr) {
            int u = it[0]-'a';
            int v = it[it.size()-1]-'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
            start = u;
        }
        
        dfs(start, vis, adj);
        for(int i=0;i<26;i++) {
            if(!vis[i] && adj[i].size()>0) return 0;    //not visited && any adjacent exists as > 0
            if(adj[i].size()%2==1) return 0;           //if odd outdegree
        }
        return 1;
    }
};
