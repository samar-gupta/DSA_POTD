//Approach-1 : 
class Solution {
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};


//Approach-2 : 
class Solution {
  public:
    int mod = 1e9+7;
    int countWays(int n) {
        // your code here
        if(n<=2) return n;
        
        int prev2=1, prev=2;
        
        for(int i=3;i<=n;i++){
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};
