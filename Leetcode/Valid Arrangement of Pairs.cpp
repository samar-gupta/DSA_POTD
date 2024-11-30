//Leetcode Link : https://leetcode.com/problems/valid-arrangement-of-pairs

//Approach-1 (DFS Using Stack) - Hierholzer's Algorithm to find Euler Path
//T.C : O(V+E) for normal DFS
//S.C : O(V+E)
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //Step-1 Build adjacency list - Graph
        unordered_map<int, vector<int>> adj;
        
        //build  indegree and outdegree
        unordered_map<int, int> indegree, outdegree;
        //key - node
        //value - indegree/outdegree

        for(auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v); //u --> v
            outdegree[u]++;
            indegree[v]++;
        }

        //Find the startNode of the Euler Path
        int startNode = pairs[0][0];
        for(auto &it :  adj) {
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        //Simply do the Khandani DFS
        vector<int> EulerPath; //to store my eulerpath
        stack<int> st; //to perform dfs
        st.push(startNode);

        while(!st.empty()) {
            int curr = st.top();
            if(!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }


        //Build your result
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;
        for(int i = 0; i < EulerPath.size()-1; i++) {
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }

        return result;
    }
};


//Approach-2 (DFS Using Recursion) - Hierholzer's Algorithm to find Euler Path
//T.C : O(V+E) for normal DFS
//S.C : O(V+E)
class Solution {
public:
    // Adjacency list
    unordered_map<int, vector<int>> adj;

    // Vector to store the Eulerian path
    vector<int> eulerPath;

    // Recursive DFS function to find the Eulerian path
    void dfs(int node) {
        while (!adj[node].empty()) {
            int nextNode = adj[node].back();
            adj[node].pop_back();  // Remove the edge after visiting
            dfs(nextNode);         // Recursive DFS call
        }
        eulerPath.push_back(node);  // Add node to Euler path after all edges are visited
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Step-1: Build adjacency list and calculate in-degree & out-degree
        unordered_map<int, int> indegree, outdegree;

        for (auto& edge : pairs) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);  // u --> v
            outdegree[u]++;
            indegree[v]++;
        }

        // Step-2: Find the start node of the Eulerian path
        int startNode = pairs[0][0];  // default start node
        for (auto& it : adj) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;  // Node with outdegree > indegree by 1
                break;
            }
        }

        // Step-3: Perform DFS from the start node to find the Eulerian path
        dfs(startNode);

        // Step-4: Build the result from the Eulerian path
        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> result;
        for (int i = 0; i < eulerPath.size() - 1; i++) {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return result;
    }
};
