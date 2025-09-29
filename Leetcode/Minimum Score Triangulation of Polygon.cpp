//Leetcode Link : https://leetcode.com/problems/minimum-score-triangulation-of-polygon

//Approach (Recursion + Memoization)
//T.C : O(n*n*n)
//S.C : O(n*n)
class Solution {
public:
    int t[50][50];

    int solve(vector<int>& values, int i, int j) {
        if (j - i < 2) 
            return 0; // less than 3 vertices -> no triangle

        if (t[i][j] != -1)
            return t[i][j];

        int result = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int weight = solve(values, i, k) +
                        values[i] * values[k] * values[j] +
                        solve(values, k, j);
            result = min(result, weight);
        }

        return t[i][j] = result;
    }

    int minScoreTriangulation(vector<int>& values) {
        memset(t, -1, sizeof(t));
        return solve(values, 0, values.size() - 1);
    }
};
