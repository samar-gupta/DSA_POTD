//Approach-1 : 
class Solution {
  public:
    bool solve(vector<vector<int>>& mat, int i, int j) {
        if (i == 9) {
            return true;
        }
        int nextI = (j == 8) ? i + 1 : i;
        int nextJ = (j == 8) ? 0 : j + 1;

        if (mat[i][j] != 0) {
            return solve(mat, nextI, nextJ);
        }
        for (int val = 1; val <= 9; val++) {
            if (isValid(mat, i, j, val)) {
                mat[i][j] = val;
                if (solve(mat, nextI, nextJ)) {
                    return true;
                }
                mat[i][j] = 0;
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<int>>& mat, int r, int c, int val) {
        for (int i = 0; i < 9; i++) {
            if (mat[i][c] == val || mat[r][i] == val)
                return false;
        }

        int strR = (r / 3) * 3;
        int strC = (c / 3) * 3;
        for (int i = strR; i < strR + 3; i++) {
            for (int j = strC; j < strC + 3; j++) {
                if (mat[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat, 0, 0);
    }
};


//Approach-2 : 
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        solve(grid);
    }
    
    bool solve(int grid[N][N]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    
                    for(int d=1;d<=9;d++){
                        if( isValid(grid,i,j,d) ){
                            grid[i][j]=d;
                            
                            if(solve(grid)==true){
                                return true;
                            }
                            else{
                                grid[i][j]=0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    
    bool isValid(int grid[N][N], int row, int col, int d){
        for(int i=0;i<9;i++){
            if(grid[row][i]==d) return false;
            if(grid[i][col]==d) return false;
            
            if( grid[3*(row/3) +i/3 ][3*(col/3) +i%3]==d) return false;
        }
        return true;
    }
    
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        if(SolveSudoku(grid)){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    cout<<grid[i][j]<<" ";
                }
            }
        }
    }
};
