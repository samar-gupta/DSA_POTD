//Approach : (Using Minimum Spnanning Tree(MSP), Prim's Algo)
class Solution {
  public:
    int prims(vector<pair<int, int>>adj[], int n){
        int sum=0;
        vector<int>vis(n,0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            int node=pq.top().second; 
            int wt=pq.top().first; 
            pq.pop(); 
            if(vis[node]==1) continue;
            
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){ 
                if(!vis[it.first]){
                    pq.push({it.second, it.first});
                }
            }
        }
        
        return sum;
    }
    
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        vector<pair<int, int>>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(houses[i][0]-houses[j][0]) + 
                          abs(houses[i][1] - houses[j][1]);
                adj[i].push_back({j, dist}); 
                adj[j].push_back({i, dist});
            }
        }
        
        return prims(adj, n);
    }
};
