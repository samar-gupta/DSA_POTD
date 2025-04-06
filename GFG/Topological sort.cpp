//Approach-1 : (Using DFS)
class Solution {
  public:
    void dfs(int start, vector<bool> &vis, stack<int> &s, vector<int> adj[]) {
	    vis[start] = 1;
	    
	    for(int nbr : adj[start]) {
	        if(!vis[nbr]) {
	            dfs(nbr, vis, s, adj);
	        }
	    }
	    
	    s.push(start);
	}
	
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<bool> vis(V);
	    stack<int> s;
	    for(int i = 0; i < V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, s, adj);
	        }
	    }
	    vector<int> res;
	    for(int i = 0; i < V; i++) {
	        res.push_back(s.top()); s.pop();
	    }
	    return res;
    }
};


//Approach-2 : (Using BFS)
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> res;
	    vector<int> indegree(V, 0);
	    
	    for(int i = 0; i < V; i++) {
	        for(int nbr : adj[i]) {
	            indegree[nbr]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int curr = q.front(); q.pop();
	        res.push_back(curr);
	        
	        for(int nbr : adj[curr]) {
	            indegree[nbr]--;
	            if(indegree[nbr] == 0) q.push(nbr);
	        }
	    }
	    
	    return res;
    }
};
