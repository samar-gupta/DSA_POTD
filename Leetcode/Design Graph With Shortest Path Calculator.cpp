/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/design-graph-with-shortest-path-calculator
*/

/******************************************************** C++ ********************************************************/
//Approach-2 (Using Floyd Warshal Algorithm) (Better, as it stores result in matrix)
//T.C : O(N^3) - Making adj Matrix
class Graph {
public:
    vector<vector<int>> adjMatrix;
    int N;

    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adjMatrix = vector<vector<int>>(n, vector<int>(n, 1e9));

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            adjMatrix[u][v] = cost;
        }

        for(int i = 0; i<n; i++) {
            adjMatrix[i][i] = 0;
        }

        //Floyd Warshall code
        for(int via = 0; via < n; via++) {

            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {

                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);

                }
            }
        }

    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        //check this edge u--->v     // i--->u--(cost)-->v--->j

        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {

                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][u] + cost + adjMatrix[v][j]);

            }
        }

    }
    
    int shortestPath(int node1, int node2) {
        return adjMatrix[node1][node2] == 1e9 ? -1 : adjMatrix[node1][node2];
    }
};





//Approach-1 (Using Dijkstra's Algorithm)
//T.C : Dijkatra's called M times - O(M * ElogV)
class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int N;
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto &vec : edges) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            
            adj[u].push_back({v, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u    = edge[0];
        int v    = edge[1];
        int cost = edge[2];
            
        adj[u].push_back({v, cost});
    }
    
    int shortestPath(int node1, int node2) {

		vector<int> result(N, INT_MAX);

		result[node1] = 0;
		pq.push({0, node1});

		while(!pq.empty()) {

		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

		    for(auto &vec : adj[node]) {

			int adjNode = vec.first;
			int dist    = vec.second;

			if(d + dist < result[adjNode]) {

			    result[adjNode] = d + dist;
			    pq.push({d+dist, adjNode});

			}

		    }

		}
        
        return result[node2] == INT_MAX ? -1 : result[node2];
    }
};
