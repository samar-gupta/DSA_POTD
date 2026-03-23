class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> next(V, -1);
        for (auto &e : edges) {
            next[e[0]] = e[1];
        }
        
        vector<int> vis(V, 0);
        vector<int> time(V, 0);
        
        int timer = 1;
        int maxCycle = -1;
        
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            
            int node = i;
            unordered_map<int, int> mp; // node → time
            
            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                mp[node] = timer++;
                node = next[node];
            }
            
            // Check cycle
            if (node != -1 && mp.count(node)) {
                int cycleLen = timer - mp[node];
                maxCycle = max(maxCycle, cycleLen);
            }
        }
        
        return maxCycle;
    }
};
