//Leetcode Link : https://leetcode.com/problems/maximum-path-score-in-a-grid

//Approach-1 (Recursion + Memoization)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost, vector<vector<vector<int>>>& t) {
        if(i >= m || j >= n)
            return INT_MIN;
        
        int newCost = cost + (grid[i][j] > 0);

        if(newCost > k)
            return INT_MIN;
        
        if(i == m-1 && j == n-1)
            return grid[i][j]; //score
        
        if(t[i][j][cost] != -1) {
            return t[i][j][cost];
        }
        
        //down
        //right
        int down  = solve(grid, k, i+1, j, newCost, t);
        int right = solve(grid, k, i, j+1, newCost, t);

        int bestNext = max(down, right);

        if(bestNext == INT_MIN) {
            return t[i][j][cost] = INT_MIN;
        }

        return t[i][j][cost] = grid[i][j] + bestNext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));

        int result = solve(grid, k, 0, 0, 0, t);

        return result == INT_MIN ? -1 : result;
    }
};


//Approach-2 (Bottom Up)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(
            m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1))
        );

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = k; cost >= 0; cost--) {

                    int newCost = cost + (grid[i][j] > 0);

                    if (newCost > k) continue;

                    // Base case: destination
                    if (i == m - 1 && j == n - 1) {
                        t[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down  = -1;
                    int right = -1;

                    if (i + 1 < m)
                        down = t[i + 1][j][newCost];

                    if (j + 1 < n)
                        right = t[i][j + 1][newCost];

                    int bestNext = max(down, right);

                    if (bestNext != -1) {
                        t[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }
        }

        return t[0][0][0];
    }
};
