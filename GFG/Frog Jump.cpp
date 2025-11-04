//Approach-1 : 
class Solution {
  public:
    int minCost(vector<int>& h) {
        // Code here
        int n = h.size();
        if (n == 1) return 0;

        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = abs(h[1] - h[0]);

        for (int i = 2; i < n; i++) {
            int one = dp[i - 1] + abs(h[i] - h[i - 1]);
            int two = dp[i - 2] + abs(h[i] - h[i - 2]);
            dp[i] = min(one, two);
        }

        return dp[n - 1];
    }
};

/*Other approaches : 
    • Recursion 
    • Recursion + Memorization 
    • Tabulation (DP) (above shown)
    • Space Optimization 
*/
