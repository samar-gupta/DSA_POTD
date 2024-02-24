//Approach-1 (Recursion)
class Solution {
    public:
        int maxSum(int n) {
            if(n<12) {
                return n;
            }
             
            int ans = maxSum(n/2)+maxSum(n/3)+maxSum(n/4);
            
            return max(ans, n);
        }
};





//Approach-2 (Recursion + Memoization)
class Solution {
    public:
        int t[1000001];
        
        int solve(int n) {
            if(n < 12) {
                return n;
            }
            
            int ans = solve(n/2) + solve(n/3) + solve(n/4);
            
            return t[n] = max(ans, n);
        }
        
        int maxSum(int n) {
            memset(t, -1, sizeof(t));
            return solve(n);
        }
};
