//Approach-1 : 
class Solution {
  public:
    int mod=1e9+7;

    int solve(int i, int target, vector<int>&arr, vector<vector<int>>&dp){
        if(i==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        
        dp[i][target]=solve(i-1, target, arr, dp)%mod;
        
        if(arr[i-1]<=target){
            dp[i][target]+=solve(i-1, target-arr[i-1], arr, dp);
            dp[i][target]%=mod;
        }
        
        return dp[i][target];
    }
  
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        
        if(total<d || (total-d)%2==1) return 0;
        
        int target=(total-d)/2;
        
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        
        return solve(n, target, arr, dp);
    }
};



//Approach-2 :
class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int totalSum = 0;
        
        // Calculate total sum of array
        for (int num : arr) {
            totalSum += num;
        }
        
        // If totalSum + diff is odd, partition is impossible
        if ((totalSum + diff) % 2 != 0) {
            return 0;
        }
        
        int target = (totalSum + diff) / 2;
        
        // dp[j] = number of ways to make sum j
        vector<int> dp(target + 1, 0);
        
        // One way to make sum 0 -> choose nothing
        dp[0] = 1;
        
        for (int num : arr) {
            // Traverse backwards to avoid reusing same element
            for (int j = target; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[target];
    }
};
