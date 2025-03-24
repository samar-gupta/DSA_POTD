class Solution {
  public:
    int mcm(vector<int>& vec, int s, int e, vector<vector<int>> &dp) 
    {
        if(s >= e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int ans = INT_MAX;
        for (int i = s; i < e; i++)
        {
            int subans = mcm(vec, s, i, dp) + mcm(vec, i + 1, e, dp) + vec[s - 1] * vec[i] * vec[e];
            ans = min(ans, subans);
        }
    
        return dp[s][e] = ans;
        
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return mcm(arr, 1, N - 1, dp);
    }
};
