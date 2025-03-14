class Solution {
  public:
    long long int help(int ind, int N, vector<int>& coins, int sum, vector<vector<long long int>>& dp){
        if(ind==N-1){
            return (sum%coins[N-1]==0);
        }
        
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        
        long long int notTake= help(ind+1,N,coins,sum,dp);
        long long int Take=0;
        if(coins[ind]<=sum){
            Take=help(ind,N,coins,sum-coins[ind],dp);
        }
        
        return dp[ind][sum]= Take+notTake;
    }
    
    int count(vector<int>& coins, int sum) {
        // code here.
        int N = coins.size();
        vector<vector<long long int>> dp(N,vector< long long int>(sum+1,-1));
        return help(0,N,coins,sum,dp);
    }
};
