//Approach-1 :
/* Intuition:
    In a Directed Acyclic Graph (DAG), no cycles are allowed, 
    which means we can always arrange all vertices in a topological order.
    In such an order, every edge points from a vertex that appears earlier to one that appears later.
    Now, if we want to make the graph as dense as possible without forming any cycle, 
    we can connect every vertex to all vertices that come after it in the topological sequence.
    
    That gives the maximum number of possible edges in a DAG with V vertices as:
        maxEdges=(V * (V - 1)) / 2.

    If the graph already has E edges, then the maximum number of new edges that can be safely added is:
        maxAdditionalEdges=(V * (V - 1)) / 2. − E

Step-by-Step Approach:
    1. Take the number of vertices V and edges E.
    2. Compute the total number of edges that a DAG can have using the formula (V * (V - 1)) / 2.
    3. Subtract the existing edges E from this total.
    4. The result represents the maximum number of edges that can be added without creating a cycle.
*/
/*Maximum number of edges in a DAG
    Vertex 1 can connect to vertices 2, 3, …, n → (n − 1) edges
    Vertex 2 can connect to vertices 3, 4, …, n → (n − 2) edges
    Vertex (n−1) can connect to vertex n → 1 edge
    So maxEdges = (n - 1) + (n - 2) + ... + 1 = n(n - 1)/2
*/
class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int E=edges.size();
        int maxPossible = (V*(V-1))/2;
        return maxPossible-E;
    }
};



//Approach-2 : (DFS and Topological Sort)
/* 
    Generate Topological sort of DAG
    check for each vertex in sorted array (u), the vertex after that (v)
    If there is no path from u to v we can add one path
*/
class Solution {
  public:
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& topoSort) {
        vis[node] = true;
        for (int nbr:adj[node]) {
            if (!vis[nbr]) dfs(nbr, adj, vis, topoSort);
        }
        topoSort.push(node);
    }
    
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        stack<int> topoSort;
        vector<vector<int>> adj(V);
        vector<bool> vis(V, false);
        vector<vector<bool>> path(V, vector<bool>(V, false));
        
        for (auto edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            path[edge[0]][edge[1]] = true;
        }
        
        for (int i=0; i<V; i++) {
            if (adj[i].size() == 0) {
                vis[i] = true;
                topoSort.push(i);
            }
        }
        
        for (int i=0; i<V; i++) {
            if (!vis[i]) dfs(i, adj, vis, topoSort);
        }
        
        vector<int> sorted;
        while (!topoSort.empty()) {
            sorted.push_back(topoSort.top());
            topoSort.pop();
        }
        
        int ans = 0;
        
        for (int i=0; i<V-1; i++) {
            for (int j=i+1; j<V; j++) {
                if (!path[sorted[i]][sorted[j]]) {
                    // cout << i << ' ' << j << '\n';
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


//Approach-3 : (Just think in terms on indegree and outdegree for a graph.)
class Solution {
  public:
    int maxEdgesToAdd(int v, vector<vector<int>>& edges) {
        // code here        
        int at_max=v-1;
        
        vector<int>indegree(v,0);
        vector<int>outdegree(v,0);
        
        for(auto e : edges){
            outdegree[e[0]]++;
            indegree[e[1]]++;
        }
        
        int total=0;
        
        for(int i=0;i<v;i++){
            int sum = indegree[i]+outdegree[i];
            total+=at_max-sum;
        }
        
        return total/2;        
    }
};
