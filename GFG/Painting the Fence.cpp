class Solution{
    public:
    int mod=1e9+7;
    long long countWays(int n, int k){
        k=(long long)k;
        if(n==1) return k;
        vector<long long>dp(n+1,0);
        dp[1]=k;
        k--;
        for(int i=2;i<=n;i++) dp[i]=((dp[i-1]+dp[i-2])*k)%mod;
        return (dp[n-1]+dp[n])%mod;
    }
};
