//Approach-1 :
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int derangeCount(int n) {
        // code here
        vector<int> dp(n+1, 0);
        dp[2] = 1;

        for(int i = 3;i <= n; i++)
            dp[i] = (i-1)*(dp[i-1]+dp[i-2]);

        return dp[n];
    }
};



//Approach-2 : (Space Optimized)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    #define mod 1000000007

    int derangeCount(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;

        long long first = 0; // D(1)
        long long second = 1; // D(2)

        for (int i = 3; i <= n; i++) {
            long long curr = ((i - 1) * (first + second) % mod) % mod;
            first = second;
            second = curr;
        }

        return second;
    }
};
