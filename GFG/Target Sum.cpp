class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int sum = 0;
        for (int x : arr)
        {
            sum += x;
        }
    
        int total=(sum+target);
        if (total % 2 != 0)
        {
            return 0;
        }
        int tar=total/2;
        if (tar < 0) 
        {
            return 0;
        }
        vector<int> dp(tar + 1, 0);
        dp[0] = 1;
    
        for (int num : arr) {
            for (int s = tar; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }
    
        return dp[tar];
    }
};
