// Approach 1: Use DFS with memoization to explore all three possible moves (right-up, right, right-down) from each cell, and cache results in a dp table to avoid recomputation.
// Time Complexity: O(n * m) — each of the n*m cells is computed at most once.
// Space Complexity: O(n * m) — dp table of size up to 501×501, plus recursion stack up to O(n + m).
class Solution {
public:

    // dfs helper that returns max gold from cell (i, j)
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();

        // base case: out of bounds or beyond last column
        if (i < 0 || i >= n || j >= m) {
            return 0;
        }

        // if already computed, reuse it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // move to right-up cell
        int rightUp = solve(i - 1, j + 1, mat, dp);
        // move to right cell
        int right = solve(i, j + 1, mat, dp);
        // move to right-down cell
        int rightDown = solve(i + 1, j + 1, mat, dp);

        // cache and return the best of three moves plus current gold
        return dp[i][j] = mat[i][j] + max({ rightUp, right, rightDown });
    }

    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int result = 0;
        // initialize dp table to -1 (uncomputed)
        vector<vector<int>> dp(501, vector<int>(501, -1));

        // try starting from each row in first column
        for (int i = 0; i < n; i++) {
            result = max(result, solve(i, 0, mat, dp));
        }
        return result;
    }
};


// Approach 2: Use bottom-up DP (tabulation) to build a dp table where dp[i][j] stores the max gold collectible from cell (i,j) moving only right-up, right, or right-down.
// Time Complexity: O(n * m) — we fill an n×m table once.
// Space Complexity: O(n * m) — we use an auxiliary dp table of size n×m.
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        // dp table of same dimensions
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // 1) Initialize last column (no moves possible)
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = mat[i][m - 1];
        }

        // 2) Build table from right to left
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int right   = dp[i][j + 1];                            // move right
                int rightUp = (i > 0     ? dp[i - 1][j + 1] : 0);      // move right-up if in bounds
                int rightDn = (i + 1 < n   ? dp[i + 1][j + 1] : 0);    // move right-down if in bounds
                dp[i][j] = mat[i][j] + max({ rightUp, right, rightDn });
            }
        }

        // 3) Collect the best starting position in column 0
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, dp[i][0]);
        }
        return result;
    }
};
