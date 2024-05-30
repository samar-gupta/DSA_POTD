class Solution {
  public:
    int mod = 1e9 + 7;
int countWays(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(s1, s2, n - 1, m - 1, dp);
}
int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (m < 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int take = 0, notake = 0;
    if (s1[n] == s2[m])
    {
        take = solve(s1, s2, n - 1, m, dp) + solve(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        notake = solve(s1, s2, n - 1, m, dp);
    }
    return dp[n][m] = (take + notake) % mod;
}
};
