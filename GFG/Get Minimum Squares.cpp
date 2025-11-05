//Approach-1 : (Recursion + Memoization)
class Solution {
  public:
    int solve(int n, vector<int>&dp){
        // base case
        if(n<=0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        int mini = n;
        for(int i=1; i*i<=n; i++){
            int res = solve(n-i*i, dp);
            mini = min(mini, res+1);
        }
        dp[n] = mini;
        return dp[n];
    }
    
    int minSquares(int n) {
        // Code here
        vector<int>dp(n+1,-1);
	    return solve(n, dp);
    }
};


//Approach-2 : (Tabulation)
class Solution {
  public:
    int minSquares(int n) {
        // Code here
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
