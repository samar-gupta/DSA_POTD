//Leetcode Link : https://leetcode.com/problems/largest-local-values-in-a-matrix

//Approach(Simply traversing and finding the result)
//T.C : O(n*n)
//S.C : O(n*n) for thr result but you can ignore it because it's the result that we have to return
class Solution {
public:
    int findLocalMax(vector<vector<int>>& grid, int x, int y) {
        int maxElement = 0;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                maxElement = max(maxElement, grid[i][j]);
            }
        }
        return maxElement;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                maxLocal[i][j] = findLocalMax(grid, i, j);
            }
        }
        return maxLocal;
    }
};
