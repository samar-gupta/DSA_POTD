//Approach-1 : 
class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> revGraph(V);
        vector<int> outdeg(V, 0);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            revGraph[v].push_back(u);
            outdeg[u]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (outdeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for (int parent : revGraph[node]) {
                outdeg[parent]--;
                if (outdeg[parent] == 0){
                    q.push(parent);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};


//old
//Approach:
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<int> arr[V];
        int indegree[V] = {0};
        
        for(int i=0; i<V; i++) {
            for(int it : adj[i]) {
                arr[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : arr[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
