//Approach-1 :
/*
    A dynamic programming-based approach is typically used for this problem. 
    The logic is:
       If length of C is not equal to the sum of lengths of A and B, return 0.
       Use a 2D DP array where dp[i][j] is true if C[0...(i+j-1)] can be formed by interleaving A[0...(i-1)] and B[0...(j-1)].
*/
class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n = A.length();
        int m = B.length();
        int l = C.length();
        if (n + m != l) 
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i > 0 && A[i - 1] == C[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (j > 0 && B[j - 1] == C[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
