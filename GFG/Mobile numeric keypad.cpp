//updated
// Approach: Use top-down DP (memoization) on a 4×3 keypad grid; from each key you can stay or move up/down/left/right, caching results in dp[i][j][len].
// Time Complexity: O(4*3*n) = O(n), since there are 12 valid keys and n sequence lengths.
// Space Complexity: O(4*3*n) = O(n), for the memoization table of size 4×3×(n+1).
class Solution {
public:

    int dp[4][3][16];

    int solve(int i, int j, int n) {
        // invalid or forbidden cells (* and #)
        if (i < 0 || i >= 4 || j < 0 || j >= 3 ||
            (i == 3 && (j == 0 || j == 2))) {
            return 0;
        }

        // base case: sequence length 1 → only the current key
        if (n == 1) {
            return 1;
        }

        // return cached result if available
        if (dp[i][j][n] != -1) {
            return dp[i][j][n];
        }

        int result = 0;
        // stay in place
        result += solve(i, j, n - 1) +
                  // move up
                  solve(i - 1, j, n - 1) +
                  // move left
                  solve(i, j - 1, n - 1) +
                  // move right
                  solve(i, j + 1, n - 1) +
                  // move down
                  solve(i + 1, j, n - 1);

        // cache and return
        return dp[i][j][n] = result;
    }

    int getCount(int n) {
        int count = 0;

        // initialize memo table
        memset(dp, -1, sizeof(dp));
        // iterate over all starting cells
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                count += solve(i, j, n);
            }
        }
        return count;
    }
};


//old
class Solution {
  public:
  unordered_map<int, vector<int>>mp;
  long long dp[11][26];
  long long solve(int n, int last, int i){
      if(i==n-1) return 1; //base case
      
      if(dp[last][i]!=-1)return dp[last][i];
      
     long long ans=0;
     for(auto itr: mp[last]){
         ans+= solve(n, itr, i+1);
     }
     
     return dp[last][i]=ans;
  }

    long long getCount(int n) {
        // Your code goes here
        long long ans=0;
        memset(dp, -1, sizeof(dp));
        
        mp[0]={0, 8};
        mp[1]={1, 2,4};
        mp[2]={1, 2,3, 5};
        mp[3]={6, 2,3};
        mp[4]={1, 4,5, 7};
        mp[5]={2, 4,5, 6, 8};
        mp[6]={3, 5,6, 9};
        mp[7]={7, 4, 8};
        mp[8]={8, 7, 9, 0,5};
        mp[9]={9, 6, 8};
      
        for(int i=0; i<=9; i++){
            ans+=solve(n, i, 0);
            // cout<<solve(n, i, 0)<<" ";
        }
      
        return ans;
    }
};
