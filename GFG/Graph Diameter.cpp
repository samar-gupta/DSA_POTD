//Approach-1 : (BFS)
/*
Simple Concept : 
   From any node Find the node1 which is at maximum distance from starting node 
   and from that find the node2 which is at maximum distance from node1.
   The distance between node1 and node2 will be the diameter of the graph.

The diameter of a tree (or any connected component of an unweighted undirected graph) 
is the longest shortest-path between any two nodes in that component. 
A well-known trick to compute the diameter is:
      a). Run BFS from any node u to find the farthest node a.
      b). Run BFS again from a to find the farthest node b. 
      c). The distance dist(a, b) is the diameter of that component.
For a graph with multiple connected components, compute the diameter of each component and take the maximum.   
*/
//T.C : O(V + E)
class Solution {
  public:
    pair<int, int> bfs(int start, vector<vector<int>>& adj, int V) {
        vector<int> dist(V, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &nbr : adj[node]) {
                if (dist[nbr] == -1) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                    if (dist[nbr] > dist[farthestNode])
                        farthestNode = nbr;
                }
            }
        }
        return {farthestNode, dist[farthestNode]};
    }

    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto first = bfs(0, adj, V);
        int nodeA = first.first;
        auto second = bfs(nodeA, adj, V);
        return second.second;
    }
};
