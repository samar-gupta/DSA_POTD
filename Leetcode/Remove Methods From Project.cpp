//Leetcode Link : https://leetcode.com/problems/remove-methods-from-project/description/

//Approach-1 - Using BFS
//T.C : O(V+E) , V = number of nodes(methods), E = number of edges
//S.C : O(V+E), V = number of nodes(methods), E = number of edges
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //O(V+E), V = nodes , E = edges
        //graph - adjacency list
        vector<vector<int>> adj(n); //u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0); //O(V)
        vector<bool> suspicious(n, false);//O(V)

        for(auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //BFS
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();

            for(int &ngbr : adj[curr]) {
                inDegree[ngbr]--;
                if(!suspicious[ngbr]) {
                    que.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;
        
        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) {
                result.push_back(i);
            }

        }

        if(cannotRemove) {
            vector<int> vec(n); //0, 1, 2,... n-1
            for(int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        
        return result;


    }
};


//Approach-2 - Using DFS
//T.C : O(V+E) , V = number of nodes(methods), E = number of edges
//S.C : O(V+E), V = number of nodes(methods), E = number of edges
class Solution {
public:
    void dfs(int curr, vector<vector<int>>& adj, vector<int>& inDegree, vector<bool>& suspicious) {
        suspicious[curr] = true;
        for(int &ngbr : adj[curr]) {
            inDegree[ngbr]--;
            if(!suspicious[ngbr]) {
                dfs(ngbr, adj, inDegree, suspicious);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //O(V+E), V = nodes , E = edges
        //graph - adjacency list
        vector<vector<int>> adj(n); //u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0); //O(V)
        vector<bool> suspicious(n, false);//O(V)
        for(auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        //DFS
        dfs(k, adj, inDegree, suspicious);
        
        vector<int> result;
        bool cannotRemove = false;
        
        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }
            if(!suspicious[i]) {
                result.push_back(i);
            }
        }
        if(cannotRemove) {
            vector<int> vec(n); //0, 1, 2,... n-1
            for(int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        
        return result;
    }
};
