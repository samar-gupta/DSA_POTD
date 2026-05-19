class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if(start == end)
            return 0;
        
        vector<int> dist(1000, 1e9);
        
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        while(!q.empty()) {
            
            int current = q.front();
            q.pop();
            
            for(int num : arr) {
                
                int next = (current * num) % 1000;
                
                if(dist[current] + 1 < dist[next]) {
                    
                    dist[next] = dist[current] + 1;
                    
                    if(next == end)
                        return dist[next];
                    
                    q.push(next);
                }
            }
        }
        
        return -1;
    }
};




//old
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        int mod=1e5;
        vector<bool> vis(mod);
        queue<pair<int,int>> q;
        q.push({0,start});
        
        vis[start]=1;
        while(!q.empty()){
            int level=q.front().first;
            int temp=q.front().second;
            
            q.pop();
            for(int i=0; i<arr.size();i++){
                int prod = (temp*arr[i])%mod;
                if(prod==end) return level+1;
                if(vis[prod]) continue;
                q.push({level+1,prod});
                vis[prod]=1;
            }
        }
        return -1;
    }
};
