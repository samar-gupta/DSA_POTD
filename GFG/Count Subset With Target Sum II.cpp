class Solution {
  public:
    int dp[41][40001];
    int solve(vector<int>& arr, int k, int i, int sum) {
        if(i == arr.size()) return (sum == k);
        
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int skip = solve(arr, k, i+1, sum);
        int take = 0;
        
        if(sum + arr[i] <= k) {
            take = solve(arr, k, i+1, sum+arr[i]);
        }
        
        return dp[i][sum] = take + skip;
    }
    
    int countSubset(vector<int> &arr, int k) {
        // code here
        int totalSum = 0;
        for (int x : arr) totalSum += x;
        if (k > totalSum) return 0;
        memset(dp, -1, sizeof(dp));
        
        return solve(arr, k, 0, 0);
    }
};
