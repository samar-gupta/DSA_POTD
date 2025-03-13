//Approach-1 : 
class Solution {
  public:
    int solve(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        if(i>=val.size()) return 0;
        if(dp[i][W]!=-1) return dp[i][W];
        int take=0;
        if(W-wt[i]>=0)
            take = val[i] + solve(i+1,W-wt[i],wt,val,dp);
        int not_take = solve(i+1,W,wt,val,dp);
        return dp[i][W] = max(take,not_take);
    }
    
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(val.size()+1, vector<int>(W+1,-1));
        return solve(0,W,wt,val,dp);        
    }
};


//Approach-2 : 
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<int> dp(W + 1, 0);
        
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        
        return dp[W];
    }
};
