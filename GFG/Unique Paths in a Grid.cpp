// Approach 1: Use memoized recursion (Top-down DP) to explore all right and down paths avoiding cells with value 1. Store intermediate results in dp to avoid recomputation.
// Time Complexity: O(n * m), where n and m are grid dimensions, since each cell is computed only once due to memoization.
// Space Complexity: O(n * m), for the dp array used in memoization.
class Solution {
public:
    // Helper function to recursively calculate number of unique paths from (i, j) to (n-1, m-1)
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();      // total number of rows
        int n = grid[0].size();   // total number of columns

        // Base case: Out of bounds or cell is blocked
        if (i >= m || j >= n || grid[i][j] == 1) {
            return 0;
        }

        // Reached the destination cell
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // If already computed, return stored result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Move to the right and down cells
        int right = solve(i, j + 1, grid, dp);
        int down  = solve(i + 1, j, grid, dp);

        // Store the total paths from current cell
        return dp[i][j] = right + down;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();      // total rows
        int n = grid[0].size();   // total columns

        // If start or end cell is blocked, no path exists
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return 0;
        }

        // Initialize dp array with -1 for memoization
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start solving from the top-left cell
        return solve(0, 0, grid, dp);
    }
};


// Approach 2: Use Bottom-Up Dynamic Programming (Tabulation). Initialize dp[0][0] = 1. Then fill the first row and column considering blocked cells. For the rest of the grid, dp[i][j] = dp[i-1][j] + dp[i][j-1] if grid[i][j] is not blocked.
// Time Complexity: O(n * m), as every cell in the grid is visited once.
// Space Complexity: O(n * m), for the 2D dp array.
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // columns

        // If starting or ending cell is blocked, return 0
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return 0;
        }

        // Create DP table
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Starting cell
        dp[0][0] = 1;

        // Fill first row
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill first column
        for (int i = 1; i < m; i++) {
            if (grid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill remaining cells
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
