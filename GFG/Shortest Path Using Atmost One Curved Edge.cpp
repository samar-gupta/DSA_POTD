//Approach-1 : 
/*
  (Intuition) :
      You are allowed to use : 
        • any number of straight edges, 
        • and at most one curved edge in the entire path.
      So the final valid path can be of two types:
        • Only straight edges
        • Straight edges → one curved edge → straight edges
      That means the curved edge will be used exactly once in the middle, 
      and the remaining parts must be covered using straight-edge-only shortest paths.
      So for a curved edge (u, v):
      a → ... → u → (curved u→v) → ... → b
      a → ... → v → (curved v→u) → ... → b
      This requires distances:
        • from a to u using straight edges
        • from a to v using straight edges
        • from u to b using straight edges
        • from v to b using straight edgesIf we know all these, we can compute the best path using that curved edge.
 
  (Approach) :
      1. Build graph with only straight edges (wt)
        Because straight edges can be used any number of times.
      2. Run Dijkstra from a on straight-edge graph
        This gives:
          dist1[x] = shortest distance from a to x using straight edges only
      3. Run Dijkstra from b on straight-edge graph
        This gives:
          dist2[x] = shortest distance from x to b using straight edges only
      4. Start with the normal straight-only path
          ans = dist1[b]
      5. Try using each curved edge once
        For curved edge (u, v, cwt):
        Two possible ways:
          a → u → curved → v → b: dist1[u] + cwt + dist2[v]
          a → v → curved → u → b: dist1[v] + cwt + dist2[u]
        Update the minimum.
     6.If all paths impossible → return -1.
  This works because once you fix which curved edge you use, the remaining path must be straight edges, 
  and those distances are already precomputed with Dijkstra.

  
  (Time Complexity) :
    Two Dijkstra runs: O((V + E) log V)
    Checking each curved edge: O(E)
    Total: O((V + E) log V)
    
  (Space Complexity) :
    Graph + distance arrays: O(V + E)
*/
class Solution {
public:
    const long long inf = 1e18;

    vector<long long> dijkstra(int n, int a, vector<vector<pair<int,int>>> &adj) {
        vector<long long> dist(n, inf);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[a] = 0;
        pq.push({0, a});

        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            long long dis = curr.first;
            int node = curr.second;
            if(dis != dist[node]) continue;

            for(auto &it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if(dist[v] > dis + wt) {
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int shortestPath(int n, int a, int b, vector<vector<int>> &edges) {
        // code here
        // Build adjacency list with ONLY straight edges
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Run Dijkstra from a and b (using straight edges only)
        vector<long long> dist1 = dijkstra(n, a, adj);
        vector<long long> dist2 = dijkstra(n, b, adj);

        long long ans = dist1[b];   // path without curved edges

        // Try using each curved edge once
        for(auto &e : edges) {
            int u = e[0], v = e[1], cwt = e[3];

            // a -> u -> curved -> v -> b
            if(dist1[u] != inf && dist2[v] != inf)
                ans = min(ans, dist1[u] + cwt + dist2[v]);

            // a -> v -> curved -> u -> b
            if(dist1[v] != inf && dist2[u] != inf)
                ans = min(ans, dist1[v] + cwt + dist2[u]);
        }

        if(ans >= inf) return -1;
        return (int)ans;
    }
};
