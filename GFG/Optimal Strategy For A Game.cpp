//Approach : (DP)
/*
(Intuition):
At any point, you have two choices:
Pick the first coin → arr[l]
Pick the last coin → arr[r]
After you choose, the opponent will also choose in a way that reduces your final score.
So when you pick, you must assume:
👉 opponent tries to minimize your gain in future rounds.

(Dynamic Programming Idea) :
Let:
  dp[l][r] = maximum coins you can collect from subarray arr[l..r]
  If you pick arr[l]:
  Opponent will choose optimally causing minimum future gain for you.
So you get:
  arr[l] + min(dp[l+2][r], dp[l+1][r-1])
If you pick arr[r]:
Opponent again reduces your final score as much as possible.
So you get:
  arr[r] + min(dp[l][r-2], dp[l+1][r-1])
Final Formula:
  dp[l][r] = max( arr[l] + min(dp[l+2][r], dp[l+1][r-1]), arr[r] + min(dp[l][r-2], dp[l+1][r-1]) )

(Dry Run) : for arr = [8, 15, 3, 7]
Step 1 — length 1 (single coins)
dp[0][0] = 8 dp[1][1] = 15 dp[2][2] = 3 dp[3][3] = 7
Step 2 — length 2
dp[0][1] = max(8,15) = 15 dp[1][2] = max(15,3) = 15 dp[2][3] = max(3,7) = 7
Step 3 — length 3
dp[0][2]: Pick 8 → 8 + min(dp[2][2]=3 , dp[1][1]=15) = 11 Pick 3 → 3 + min(dp[0][0]=8 , dp[1][1]=15) = 11 dp[0][2] = 11 dp[1][3]: Pick 15 → 15 + min(dp[3][3]=7 , dp[2][2]=3) = 18 Pick 7 → 7 + min(dp[1][1]=15 , dp[2][2]=3) = 10 dp[1][3] = 18
Step 4 — length 4 (full array)
dp[0][3]: Pick 8 → 8 + min(dp[2][3]=7 , dp[1][2]=15) = 15 Pick 7 → 7 + min(dp[0][1]=15 , dp[1][2]=15) = 22 ← larger dp[0][3] = 22
🎉 Final answer = 22

(Time & Space Complexity) :
Type	Complexity
Time	O(n²)
Space	O(n²)

*/
class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        vector<vector<long long>> dp(n,vector<long long>(n,0));

        for(int i=0;i<n;i++){
            for (int l=0,r=i;r<n;l++,r++){
                long long x=(l+2<=r) ? dp[l+2][r] : 0;
                long long y=(l+1<=r-1) ? dp[l+1][r-1] : 0;
                long long z=(l<=r-2) ? dp[l][r-2] : 0;

                dp[l][r]=max(arr[l]+min(x,y),arr[r]+min(y,z));
            }
        }
        
        return dp[0][n-1];
    }
};


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
