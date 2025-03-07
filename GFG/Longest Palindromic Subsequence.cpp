//Approach-1 : Recursion (TLE)
//T.C : O(2^n)
//S.C : O(n)
int f(int i, int j, string A, string rev)
{
    if (i<0 || j <0) return 0;
    if (A[i] == rev[j])
        return 1 + f(i - 1, j - 1, A, rev);
    else
        return max (f(i, j - 1, A, rev), f(i - 1, j, A, rev));
}

int longestPalinSubseq(string A)
{
    int n = A.size();
    string rev = A;
    reverse(rev.begin(), rev.end());
    return f(n - 1, n - 1, A, rev);
}


//Approach-2 : (Memoization)
//T.C : O(n^2)
//S.C : O(n^2)
int f (int i, int j, string A, string rev, vector<vector<int>>& dp){

    if(i<0 || j<0)
        return 0;
        
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(A[i] == rev[j])
        return dp[i][j] = 1 + f (i-1, j-1, A, rev, dp);
    
    else 
        return dp[i][j] = max(f(i, j-1, A, rev, dp), f(i-1, j, A, rev, dp));
}


int longestPalinSubseq(string A) {
    
    int n=A.size();
    string rev = A;
    reverse(rev.begin(), rev.end());
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(n - 1, n - 1, A, rev, dp);
}


//Approach-3 : (Tabulation) (Bottom-up)
//T.C : O(n^2)
//S.C : O(n^2)
int longestPalinSubseq(string A) {
    string rev = A;
    reverse(rev.begin(), rev.end());
    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==rev[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}


//Approach-4 : (Space Optimization)
//T.C : O(n^2)
//S.C : O(n)
//We can further space optimize this tabulation solution by using 1D vector instead of 2D vector.
//prev will be used where dp[i - 1] was used 
//and curr will be used where dp[i] was used.
class Solution {
  public:
    int longestPalinSubseq(string &A) {
        // code here
        string rev = A;
        reverse(rev.begin(), rev.end());
        int n = A.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(A[i-1] == rev[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1],prev[j]);
            }
            prev = curr;
        }
        return prev[n];
    }
};
