//Leetcode Link : https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i

//Approach-1 (Using BFS)
//T.C : O(V*(V+E))
//S.C : O(V+E)
class Solution {
public:

    int bfs(int curr, unordered_map<int, vector<int>>& adj, int d, int N) {

        queue<pair<int, int>> que;
        que.push({curr, 0});
        vector<bool> visited(N, false);
        visited[curr] = true;

        int count = 0; //count the target nodes
        while(!que.empty()) {
            int currNode = que.front().first;
            int dist = que.front().second;
            que.pop();

            if(dist > d) {
                continue;
            }

            count++; //include current node in targetNodes count
            //visit neighbors of currNode
            for(auto &ngbr : adj[currNode]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist+1});
                }
            }

        }

        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size()+1;

        //adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for(int i = 0; i < N; i++) {
            result[i] = bfs(i, adj, d, N);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        //Tree 1 me kitne nodes hain
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k); //stores targetnodes count from each node within tree1 within k distance
        vector<int> result2 = findCount(edges2, k-1); //stores targetnodes count from each node within tree2 within k-1 distance

        int maxTargetNodesCount = *max_element(begin(result2), end(result2));
        
        for(int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};



//Approach-2 (Using DFS)
//T.C : O(V*(V+E))
//S.C : O(V+E)
class Solution {
public:

    int dfs(int curr, unordered_map<int, vector<int>>& adj, int d, int currNodeKaParent) {
        if(d < 0)
            return 0;
        
        int count = 1; //counting current node as 1

        for(int &ngbr : adj[curr]) {
            if(ngbr != currNodeKaParent) {
                count += dfs(ngbr, adj, d-1, curr);
            }
        }

        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size()+1;

        //adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for(int i = 0; i < N; i++) {
            result[i] = dfs(i, adj, d, -1);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        //Tree 1 me kitne nodes hain
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k); //stores targetnodes count from each node within tree1 within k distance
        vector<int> result2 = findCount(edges2, k-1); //stores targetnodes count from each node within tree2 within k-1 distance

        int maxTargetNodesCount = *max_element(begin(result2), end(result2));
        
        for(int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};
