class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        vector<int>dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        for(int i=4;i<=n;i++){
            dp[i]=((i-1)*dp[i-2]+dp[i-1]);
        }
        return dp[n];
    }
};
