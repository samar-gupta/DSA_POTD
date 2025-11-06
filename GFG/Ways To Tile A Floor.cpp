//Approach-1 : (DP) (Hint : Fibonacci Series)
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int f(int n, vector<int> &dp) {
        if (n == 0) return 1;
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        dp[n] = f(n - 1, dp) + f(n - 2, dp);
        return dp[n];
    }
    
    int numberOfWays(int n) {
        // code here
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};


//Approach-2 : (Space Optimized)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        // Simple fibonacci pattern
         if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int prev2 = 1;
        int prev1 = 2;
        int curr;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
