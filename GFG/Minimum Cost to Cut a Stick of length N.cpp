//Approach-1 :
class Solution {
  public:
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
        for (int len = 2; len < m + 2; len++) {
            for (int i = 0; i + len < m + 2; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                        dp[i][k] + dp[k][j] + cuts[j] - cuts[i]
                    );
                }
                if (dp[i][j] == INT_MAX) dp[i][j] = 0;
            }
        }
        return dp[0][m + 1];
    }
};
