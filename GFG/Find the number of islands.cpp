//updated
//Approach-1 : (Using DFS)
class Solution {
  public:
    int n,m;
    void solve(vector<vector<char>>& grid, int i, int j){
        //base case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='W'){
            return;
        }


        grid[i][j]='W';
        solve(grid,i-1,j-1);//left upper diagonal
        solve(grid,i-1,j+1);//right upper diagonal
        solve(grid,i+1,j-1);//left lower diagonal
        solve(grid,i+1,j+1);//right lower diagonal
        solve(grid,i,j-1);//left
        solve(grid,i,j+1);//right
        solve(grid,i-1,j);//up
        solve(grid,i+1,j);//down
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L'){
                    solve(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//Approach-2 : (Using BFS)
class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid,
            int n, int m){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row, col});
        while(!q.empty()){
            row=q.front().first;
            col=q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0) continue;
                    else{
                        int nrow=row+i, ncol=col+j;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] &&
                        grid[nrow][ncol]=='L'){
                            vis[nrow][ncol]=1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
        return ;
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && vis[i][j]==0){
                    ans++;
                    bfs(i, j, vis, grid, n, m);
                }
            }
        }
        return ans;
        
    }
};



//old version  ------
class Solution {
  public:
    int n,m;
    void solve(vector<vector<char>>& grid, int i, int j){
        //base case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
            return;
        }


        grid[i][j]='0';
        solve(grid,i-1,j-1);//left upper diagonal
        solve(grid,i-1,j+1);//right upper diagonal
        solve(grid,i+1,j-1);//left lower diagonal
        solve(grid,i+1,j+1);//right lower diagonal
        solve(grid,i,j-1);//left
        solve(grid,i,j+1);//right
        solve(grid,i-1,j);//up
        solve(grid,i+1,j);//down
    }

    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    solve(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
