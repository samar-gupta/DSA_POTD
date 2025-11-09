//Approach-1 : 
/* (Intuition / Approach) :
    The robot has to:
        1. Go from (0,0) to (n-1,n-1) (only right or down)
        2. Then come back to (0,0) (only left or up)
    But thinking about 2 separate trips makes the problem complicated because:
        • After collecting chocolates once, that cell becomes 0 for the next visit.
        • Paths must be valid both ways.
        • There might be blocked cells.
Key Trick
    Instead of thinking:
       • Go there → Return back
    We think:
       Two robots start at (0,0) and move to (n-1,n-1) simultaneously.
       Both robots move one step at a time such that both:
       • Can move Right or Down
       • Take exactly the same number of steps k = i + j
    So:
    Robot1: (i1, j1) = (i1, k-i1) 
    Robot2: (i2, j2) = (i2, k-i2)
    If both reach the same cell, we count the chocolates only once.
    This perfectly simulates:
        • The forward trip path
        • The return trip path
        • And ensures we don’t double count or go through blocked cells.


DP State :
    dp[k][i1][i2] = maximum chocolates collected after k steps when Robot1 is at (i1, k-i1) and Robot2 is at (i2, k-i2)

Transition (4 ways both robots can move):
    Robot1 Move	   Robot2 Move	   Previous State Used
     Down	          Down	          dp[k-1][i1-1][i2-1]
     Down           Right	          dp[k-1][i1-1][i2]
     Right	        Down	          dp[k-1][i1][i2-1]
     Right	        Right	          dp[k-1][i1][i2]
We pick the best previous state.

Final Answer :
    After 2n-2 steps, both must be at:
    (dp[2*n-2][n-1][n-1])
    If it's invalid → return 0.

Time Complexity :
Dimension	   Range
 k	      0 to 2n-2 → O(n)
 i1	      0 to n-1 → O(n)
 i2	      0 to n-1 → O(n)
 
Total = O(n³) ✅ (Matches constraints)

Space Complexity :
    dp array size = (2n) * n * n → O(n³)
    
*/
class Solution {
  public:
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        
        if(mat[0][0]==-1 || mat[n-1][n-1]==-1){
            return 0;
        }

        vector<vector<vector<int>>> dp(2*n-1,vector<vector<int>>(n,vector<int>(n,-1e9)));

        // starting position
        dp[0][0][0] = mat[0][0];

        for(int k=1; k<2*n-1;k++){
            for(int i1=0;i1<n;i1++){
                for(int i2 = 0;i2<n;i2++){
                    int j1 = k - i1;
                    int j2 = k - i2;

                    // out of bounds
                    if(j1<0 || j1>=n || j2<0 || j2>=n){
                        continue;
                    }
                    // blocked
                    if(mat[i1][j1]==-1 || mat[i2][j2]==-1){
                        continue;
                    }

                    int val=mat[i1][j1];
                    if(i1 != i2){ // avoid double counting if same cell
                        val+=mat[i2][j2];
                    }
                    
                    int best=-1e9;
                    // 4 transitions
                    if(i1>0 && i2>0){ 
                        best = max(best, dp[k-1][i1-1][i2-1]); 
                    }
                    if(i1>0 && j2>0){
                        best = max(best, dp[k-1][i1-1][i2]);   
                        
                    }
                    if(j1>0 && i2>0){
                        best = max(best, dp[k-1][i1][i2-1]);   
                        
                    } 
                    if(j1>0 && j2>0){
                        best = max(best, dp[k-1][i1][i2]);     
                        
                    }

                    if(best!=-1e9){
                        dp[k][i1][i2]=best+val;
                    }
                        
                }
            }
        }

        return max(0, dp[2*n-2][n-1][n-1]);
    }
};
