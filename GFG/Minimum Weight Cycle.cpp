//Approach-1 : 
//For every edge --> O(E), find shortest path --> O(VlogV) with Dijkstra
//T.C : O(E*(VlogV))
/* Steps :-
min_cycle = ♾️
for each edge (u, v) in graph:
    remove edge (u, v)
    dist = shortest_path(u, v)
    if dist != ∞:
        min_cycle min(min_cycle, dist + weight(u, v))
    restore edge (u, v)
*/
class Solution {
  public:
    void getGraph(vector<vector<pair<int, int>>> &adjList, vector<vector<int>>& edges, int V){
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
    }
    
    int getDistance(vector<vector<pair<int, int>>> &adjList, int src, int dest, int V){ 
        vector<int> dist(V, INT_MAX); 
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        pq.push({0, src});
        
        while(pq.size()>0){
            pair<int, int> topNode = pq.top();
            pq.pop();
            
            int u = topNode.second;
            int d = topNode.first;
            if(d>dist[u])
                continue;
            for(int i=0; i<adjList[u].size(); i++){ 
                int v = adjList[u][i].first;
                int wt = adjList[u][i].second; 
                if((u==src && v==dest) || (v==src && u==dest))
                    continue; 
                if(dist[v]>(wt + d)) { 
                    dist[v] = wt+d; 
                    pq.push({dist[v], v}); 
                }
            }
        }
    
        return dist[dest];
    }
    

    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adjList(V);
        int minCycleCost = INT_MAX;
        getGraph(adjList, edges, V);
        
        for(int i=0; i<edges.size(); i++){
            int distance = getDistance(adjList, edges[i][0], edges[i][1],V);
            if(distance != INT_MAX) {
                minCycleCost = min(minCycleCost, distance + edges[i][2]); 
            }
        }
        return minCycleCost;
    }
};
