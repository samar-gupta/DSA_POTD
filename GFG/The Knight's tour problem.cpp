//Approach-1 : 
class Solution {
  public:
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n, -1));
        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        function<bool(int, int, int)> isSafe = [&](int x, int y, int n) {
            return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
        };

        function<bool(int, int, int)> solve = [&](int x, int y, int step) {
            if (step == n * n) return true;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isSafe(nx, ny, n)) {
                    board[nx][ny] = step;
                    if (solve(nx, ny, step + 1)) return true;
                    board[nx][ny] = -1;
                }
            }
            return false;
        };

        board[0][0] = 0;
        if (solve(0, 0, 1)) return board;

        return {};
    }
};


//Approach-1 : 
class Solution {
  public:
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    bool isSafe(int x, int y, int n, vector<vector<int>>& board) {
        return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
    }
    
    bool solve(int x, int y, int step, int n, vector<vector<int>>& board) {
        if (step == n*n) return true; // All cells visited
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isSafe(nx, ny, n, board)) {
                board[nx][ny] = step;
                if (solve(nx, ny, step+1, n, board))
                    return true;
                board[nx][ny] = -1; // Backtrack
            }
        }
        return false;
    }
    
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0; // Start position
        
        if (solve(0, 0, 1, n, board))
            return board; 
        
        return {};
    }
};
