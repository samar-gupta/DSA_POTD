class Solution
{
    public:
    int solve(int n, int x, int y, int z, vector<int>&dp){
        
        if(n<0) return INT_MIN;
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        
        int cl1=solve(n-x, x, y, z, dp);
        int cl2=solve(n-y, x, y, z, dp);
        int cl3=solve(n-z, x, y, z, dp);
        
        return dp[n]=1+max(cl1, max(cl2, cl3));
    }

    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1, -1);
        return max(0, solve(n, x, y, z, dp));
    }
};
