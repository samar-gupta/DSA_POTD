class Solution {
  public:
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Push boundary 1s
        for(int i=0; i<n; i++){

            if(grid[i][0] == 1){
                q.push({i,0});
                grid[i][0] = -1;
            }

            if(grid[i][m-1] == 1){
                q.push({i,m-1});
                grid[i][m-1] = -1;
            }
        }

        for(int j=0; j<m; j++){

            if(grid[0][j] == 1){
                q.push({0,j});
                grid[0][j] = -1;
            }

            if(grid[n-1][j] == 1){
                q.push({n-1,j});
                grid[n-1][j] = -1;
            }
        }

        // BFS
        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Up
            if(i-1>=0 && grid[i-1][j]==1){
                q.push({i-1,j});
                grid[i-1][j] = -1;
            }

            // Down
            if(i+1<n && grid[i+1][j]==1){
                q.push({i+1,j});
                grid[i+1][j] = -1;
            }

            // Left
            if(j-1>=0 && grid[i][j-1]==1){
                q.push({i,j-1});
                grid[i][j-1] = -1;
            }

            // Right
            if(j+1<m && grid[i][j+1]==1){
                q.push({i,j+1});
                grid[i][j+1] = -1;
            }
        }

        // Count remaining 1s
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};
