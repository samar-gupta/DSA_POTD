class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool isValid(int n, int x, int y){
	    if(x >= 0 && x < n && y >= 0 && y < n){
	        return true;
	    }
	    
	  return false;
     }
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>> > pq;
        
        pq.push({0, {0, 0}});
        
        dist[0][0] = grid[0][0];
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            for(int i = 0; i < 4; i++){
                int a = x + dx[i];
                int b = y + dy[i];
                
                if(isValid(n, a, b) && dist[a][b] > dist[x][y] + grid[a][b]){
                    dist[a][b] = dist[x][y] + grid[a][b];
                    pq.push({dist[a][b], {a, b}});
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
};
