//Approach-1 : 
/*
(Intuition) :
    We have several piles of stones, and we can only merge exactly k consecutive piles into one.
    Each merge costs the sum of stones in those k piles.
    We must find the minimum total cost to merge everything into one pile.

    However, since each merge reduces the number of piles by (k - 1),
    it’s not always possible to end up with exactly one pile — so we must first check feasibility.


(Key Observations) :
    1. Feasibility Check:
        • After each merge, number of piles decreases by (k - 1).
        • To end with 1 pile:
            (n - 1) % (k - 1) == 0
            If not, return -1.
    
    2. Cost Pattern:
        • Whenever we merge k piles, cost = sum of those piles.
        • So we need to carefully decide which segments to merge to minimize total cost.
    
    3. Overlapping Subproblems:
        • The cost of merging piles [i..j] depends on smaller segments inside it, e.g., [i..m] and [m+1..j].
        • That’s why we use Dynamic Programming (DP).


(DP Approach) :
    DP Definition:
    Let
    dp[i][j] = minimum cost to merge stones from index i to j into as few piles as possible
        • At the end, dp[0][n-1] gives the minimum cost to merge all piles into one.
    
    DP Transition:
    We try splitting the range [i..j] into two parts at index m:
    dp[i][j] = min( dp[i][m] + dp[m+1][j] ) for all m in [i, j)
    But here’s the catch —
    since we can only merge groups of k piles, valid splits happen every (k - 1) steps.
    That’s why we loop:
    for (m = i; m < j; m += (k - 1))
    This ensures we only combine states that can lead to valid merges.
    
    When can we add merge cost?
    Only when the number of piles in [i..j] can form exactly one pile:
    if ((len - 1) % (k - 1) == 0) dp[i][j] += sum(i, j)
    sum(i, j) is precomputed using a prefix sum array for O(1) range sum queries.


(Time Complexity) :
    • There are O(n²) subproblems (i and j pairs).
    • For each subproblem, we iterate over possible split points in steps of (k - 1), up to O(n).
👉 Total Time Complexity:O(n³ / (k - 1)) ≈ O(n³) 


(Space Complexity) :
    • dp table of size n × n → O(n²)
    • prefix array → O(n)
👉 Total Space Complexity:(n²)

*/
class Solution {
  private:
    int rangeSum(vector<int> &prefix,int i,int j) {
        return prefix[j+1]-prefix[i];
    }
    
  public:
    int mergeStones(vector<int> &stones, int k) {
        // code here
        int n = stones.size();
        
        // Step 1: Feasibility Check
        if((n-1) % (k-1)!=0){
            return -1;
        }
        
        // Step 2: Prefix Sum
        vector<int> prefix(n+1,0);
        
        for (int i=0; i<n;i++){
            prefix[i+1]=prefix[i]+stones[i];
        } 
            
        
        // Step 3: DP initialization
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Step 4: Process by segment length
        for(int len=k;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                dp[i][j]=INT_MAX;
                
                // Try merging subparts in steps of (k - 1)
                for(int m=i;m< j;m+=(k-1)){
                    dp[i][j]=min(dp[i][j],dp[i][m] + dp[m+1][j]);
                }
                
                // If this segment can form exactly 1 pile, add cost
                if((len-1) % (k-1)==0){
                    dp[i][j]+=rangeSum(prefix,i,j);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
