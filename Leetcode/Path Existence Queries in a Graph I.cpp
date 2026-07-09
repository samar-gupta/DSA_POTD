//Leetcode Link : https://leetcode.com/problems/path-existence-queries-in-a-graph-i

//Approach-1 (Using DFS for each query) - TLE
//T.C : O(q * (V+E)), q = number of queries, V + E is for DFS, V = number of vertices, E = number of edges
//S.C : O(V+E), V = number of vertices, E = number of edges
class Solution {
public:
    bool dfs(int cur, int target, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        if (cur == target) 
            return true;

        visited[cur] = true;

        for (int& ngbr : adj[cur]) {
            if (!visited[ngbr]) {
                if (dfs(ngbr, target, adj, visited)) 
                    return true;
            }
        }

        return false;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
        }

        vector<bool> result;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            vector<bool> visited(n, false);
            result.push_back(dfs(u, v, adj, visited));
        }
        return result;
    }
};


//Approach-2 (Using DFS once and then mark component) - TLE
//T.C : O((V+E) + q), V + E is for DFS, V = number of vertices, E = number of edges
//S.C : O(V+E), V = number of vertices, E = number of edges
class Solution {
public:
    void dfs(int cur, int compId, unordered_map<int, vector<int>>& adj, vector<int>& component) {
        component[cur] = compId;
        for (int& ngbr : adj[cur]) {
            if (component[ngbr] == -1) {
                dfs(ngbr, compId, adj, component);
            }
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
        }

        vector<int> component(n, -1);
        int compId = 0;
        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                dfs(i, compId, adj, component);
                compId++;
            }
        }


        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(component[query[0]] == component[query[1]]);
        }
        return result;
    }
};


//Approach-3 (Simple observation - assign components)
//T.C : O(n+q)
//S.C : O(n)
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, -1);
        int compId = 0;
        component[0] = compId;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] > maxDiff) {
                compId++;
            }
            component[i] = compId;
        }


        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(component[query[0]] == component[query[1]]);
        }
        return result;
    }
};
