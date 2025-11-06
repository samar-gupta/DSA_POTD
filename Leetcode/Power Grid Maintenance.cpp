//Leetcode Link : https://leetcode.com/problems/power-grid-maintenance

//Approach-1 (Using DFS)
//T.C : O((c + n) + q log c)
//S.C : O(c + n)
class Solution {
public:
    unordered_map<int, set<int>> componentStations; 

    void dfs(int node, unordered_map<int, vector<int>>& adj,
             vector<int>& visited, int componentId, vector<int>& componentOf)  {
        visited[node] = 1;
        componentOf[node] = componentId;
        componentStations[componentId].insert(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, componentId, componentOf);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj; 
        vector<int> visited(c + 1, 0);
        vector<int> componentOf(c + 1);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int node = 1; node <= c; node++) {
            if (!visited[node]) {
                dfs(node, adj, visited, node, componentOf);
            }
        }

        vector<int> result;

        // Process queries
        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int compId = componentOf[x];

            if (type == 1) {
                if (componentStations[compId].count(x)) {
                    result.push_back(x);
                } 
                else if (!componentStations[compId].empty()) {
                    result.push_back(*componentStations[compId].begin());
                } 
                else {
                    result.push_back(-1);
                }
            } 
            else { 
                componentStations[compId].erase(x);
            }
        }

        return result;
    }
};


//Approach-2 (Using BFS)


//Approach-3 (Using DSU)
