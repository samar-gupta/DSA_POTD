// Approach-1 :  MEMOIZATION
class Solution {
public:
	int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
		if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
			return -1e9; // A very large negative value to represent an invalid position

		if (i == n - 1) {
			if (j1 == j2)
				return grid[i][j1];
			else
				return grid[i][j1] + grid[i][j2];
		}

		if (dp[i][j1][j2] != -1)
			return dp[i][j1][j2];

		int maxi = INT_MIN;

		// --- Try all possible moves (up, left, right) for both positions (j1, j2) ---
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				int ans;

				if (j1 == j2)
					ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
				else
					ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);

				// Update the maximum result
				maxi = max(maxi, ans);
			}
		}

		return dp[i][j1][j2] = maxi;
	}

	int maxChocolate(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
		return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
	}

};


// Approach-2: TABULATIONS
class Solution {
public:
	int maxChocolate(vector<vector<int>> &grid) {
		int n = grid.size();
		int m = grid[0].size();

		// Create a 3D DP array to store computed results
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

		// BASE CASE: initialize the DP array for the last row
		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = 0; j2 < m; j2++) {
				if (j1 == j2)
					dp[n - 1][j1][j2] = grid[n - 1][j1];
				else
					dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
			}
		}

		// Outer nested loops for traversing the DP array from the second-to-last row up to the first row
		for (int i = n - 2; i >= 0; i--) {
			for (int j1 = 0; j1 < m; j1++) {
				for (int j2 = 0; j2 < m; j2++) {
					int maxi = INT_MIN;

					// Inner nested loops to try out 9 options (diagonal moves)
					for (int di = -1; di <= 1; di++) {
						for (int dj = -1; dj <= 1; dj++) {
							int ans;

							if (j1 == j2)
								ans = grid[i][j1];
							else
								ans = grid[i][j1] + grid[i][j2];

							if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
								ans += -1e9; // A very large negative value to represent an invalid move
							else
								ans += dp[i + 1][j1 + di][j2 + dj];

							maxi = max(ans, maxi);
						}
					}
					dp[i][j1][j2] = maxi;
				}
			}
		}

		return dp[0][0][m - 1];
	}

};
