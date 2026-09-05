class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        vector<int>dp(n,0);
        
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int maxi=0;
            for(int j=i+1;j<n;j++){
                if(abs(a[i]-a[j])==1){
                    maxi=max(maxi, dp[j]);
                }
            }
            dp[i]=1+maxi;
            ans=max(ans, dp[i]);
        }
        return ans;
        
    }
};



//Approach :
class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        // code here
        unordered_map<int, int> dp;

        int ans = 0;

        for (int x : arr) {
            int left = dp.count(x - 1) ? dp[x - 1] : 0;
            int right = dp.count(x + 1) ? dp[x + 1] : 0;

            int current = max(left, right) + 1;

            dp[x] = current;

            ans = max(ans, current);
        }

        return ans;
    }
};
