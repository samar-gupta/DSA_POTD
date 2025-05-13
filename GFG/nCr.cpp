// ![Combination Formula](https://github.com/samar-gupta/DSA_POTD/blob/main/GFG/nCr.png?raw=true)

class Solution {
  public:
    int mod = 1e9+7;
    int nCr(int n, int r) {
        // code here
        if (r > n)
            return 0;
        vector<int> prev(r+1),curr(r+1);
        prev[0] = curr[0] = 1;
        if(r == n || r == 0){
            return 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= r; j++)
            {
                curr[j] = (prev[j - 1] + prev[j])%mod;
            }
            prev = curr;
        }
        return prev[r];
    }
};
