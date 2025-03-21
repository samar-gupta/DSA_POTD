//Approach-1 : (Recursive + Memoization(Top-Down DP)) 
//T.C : O(n) 
//S.C : O(n) + O(n)
class Solution {
  public:
    int lootScheme(vector<int>& arr, int n, vector<int> &dp){
        if(n == 0) return arr[n];
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int loota = arr[n] + lootScheme(arr, n-2, dp);
        int nhiLoota = 0 + lootScheme(arr, n-1, dp);
        
        return dp[n] = max(loota, nhiLoota);
    }
    
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return lootScheme(arr, n-1, dp);
    }
};


//Approach-2 : (Tabulation(Bottom-Up DP))
//TC : O(n) 
//SC : O(n)
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, 0);
        if(n == 1) return arr[0];
        if(n == 2) return max(arr[0], arr[1]);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i = 2; i < n; i++) {
            dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};


//Approach-3 : (Space Optimized)
//TC : O(n) 
//SC : O(1)
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int prev = arr[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            int loota = arr[i];
            
            if(i > 1) loota += prev2;
            int nhiLoota = 0 + prev;
            
            int curr_i = max(loota, nhiLoota);
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
};
