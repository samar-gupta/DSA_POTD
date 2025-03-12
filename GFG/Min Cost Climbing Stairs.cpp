//Approach-1 : (Using Top-Down)
class Solution {
  public:
    int solveTD(vector<int>&cost,int n,vector<int>&dp){
        if(n==0||n==1)return cost[n];
        if(dp[n]!=-1)return dp[n];
        return dp[n]=cost[n]+min(solveTD(cost,n-1,dp),solveTD(cost,n-2,dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int N = cost.size();
        vector<int>dp(N,-1);
        int ans=min(solveTD(cost,N-1,dp),solveTD(cost,N-2,dp));
        return ans;
    }
};


//Approach-2 : (Bottom-Up)
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int N = cost.size();
        vector<int>dp(N,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<N;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[N-1],dp[N-2]);
    }
};


//Approach-3 : (Space Optimization)
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int N = cost.size();
        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2;i<N;i++){
            int curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }
};
