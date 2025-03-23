class Solution {
  public:
    const int mod = 1e9+7;
    int dp[10001];
    
    int solve(int i, int n, string &digits) {
        if(digits[i] == '0') return 0;
	    if(i >= n) return 1;
	    if(dp[i] != -1) return dp[i];
	    int ans = 0;
	    
   	    if(digits[i] != '0') {
   	        ans += solve(i+1, n, digits);
	    }
	    if(i+1 < n && ((digits[i] == '1' && digits[i+1] <= '9') || (digits[i] == '2' && digits[i+1] < '7'))) {
	        ans += solve(i+2, n, digits);
	    }
	    return dp[i] = ans%mod;
    }
    
    int countWays(string &digits) {
        // Code here
        int n = str.size();
        memset(dp,-1,sizeof(dp));
	    return solve(0, n, digits);
    }
};
