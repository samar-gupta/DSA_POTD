class Solution {
  public:
    int editDistance(string str1, string str2) {
        // Code here
        int m = str1.length();
        int n = str2.length();
        
        // Create a DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Initialize first row and column
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i - 1][j],     // Delete
                                        dp[i][j - 1],     // Insert
                                        dp[i - 1][j - 1]  // Replace
                                       });
            }
        }
        
        // Return the minimum number of operations
        return dp[m][n];
    }
};
