//Leetcode Link : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

//Approach-1 : (Recursion + Memo)
class Solution {
public:
    int m; //rows
    int n; //cols
    vector<int> directions = {-1, 0, 1};  
    int DFS(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& t) {
        if (t[row][col] != -1) {
            return t[row][col];
        }
        
        int moves = 0;
        for(int &dir : directions) {       
            int newRow = row+dir;     
            int newCol = col+1;
            
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col]) { 
                moves = max(moves, 1+DFS(newRow, newCol, grid, t));
            }
        } 
        
        return t[row] [col] = moves;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int result = 0 ;
        
        vector<vector<int>> t(m, vector<int>(n, -1));
        
        for(int row = 0; row < m; row++) {
            result = max(result, DFS(row, 0, grid, t)); 
        }
        
        return result;
    }
};


//Approach-2:
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxMoves = 0;

        for (int col = n - 2; col >= 0; --col) {
            for (int row = 0; row < m; ++row) {
                if (row > 0 && grid[row][col] < grid[row - 1][col + 1]) {
                    dp[row][col] = max(dp[row][col], dp[row - 1][col + 1] + 1);
                }
                if (grid[row][col] < grid[row][col + 1]) {
                    dp[row][col] = max(dp[row][col], dp[row][col + 1] + 1);
                }
                if (row < m - 1 && grid[row][col] < grid[row + 1][col + 1]) {
                    dp[row][col] = max(dp[row][col], dp[row + 1][col + 1] + 1);
                }
            }
        }

        for (int row = 0; row < m; ++row) {
            maxMoves = max(maxMoves, dp[row][0]);
        }
        return maxMoves;
    }
};
