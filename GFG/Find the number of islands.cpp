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
