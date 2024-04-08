//Approach :  we have two options at each player chance either take last or first . now in game type problem to maximise our score we will take maximum of two option on our chance and minimum of two option on other chance. and after all we store results in dp to avoid tle and return the answer.

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int arr[], int left, int right, vector<vector<long long>>&dp){
        if(left>right) return 0;
        if(left==right) return arr[left];
        if(dp[left][right]!=-1) return dp[left][right];
        
        long long l=arr[left]+min(solve(arr, left+2, right, dp), solve(arr, left+1, right-1,dp));
        long long r=arr[right]+min(solve(arr, left, right-2, dp), solve(arr, left+1, right-1,dp));
        
        return dp[left][right] = max(l,r);
    }
    
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>>dp(n+1, vector<long long>(n+1, -1));
        long long ans=solve(arr, 0, n-1, dp);
        return ans;
    }
};
