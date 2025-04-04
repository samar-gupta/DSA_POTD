//Approach-1 : (Using BFS)
class Solution {
  public:
    bool helper(int start, vector<int>adj[], vector<int>&vis){
        vis[start]=1;
        queue<pair<int,int>>q;
        q.push({-1, start});
        while(!q.empty()){
            int parent=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({node, it});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges)) {
        // Code here
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};


//Approach-2 : (Using DFS)
class Solution {
  public:
    bool dfs(vector<vector<int>> &adj, vector<bool>& vis, int source, int parent)
    {
        vis[source] = true;
        
        for(auto u : adj[source])
        {
            if(vis[u] == false)
            {
                if(dfs(adj, vis, u, source))
                {
                    return true;
                }
            }
            else if(u != parent)     //visited and not parent, hence cycle is present
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V); 
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<bool> vis(V, false);
        
        for(int i = 0; i < V; i++) {
            if(vis[i] == false) {
                if(dfs(adj, vis, i, -1)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
