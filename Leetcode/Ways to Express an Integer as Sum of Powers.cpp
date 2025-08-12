//Leetcode Link : https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers

//Approach-1 (Recursion + Memoization)
//T.C : O(n*n), assuming that num can go till n in worst case (At max states = t[n][n])
//S.C : O(n*n), assuming that num can go till n in worst case (we took t[n][n])
class Solution {
public:

    int M = 1e9+7;
    int t[301][301];

    int solve(int n, int num, int x) {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        int currPowerValue = pow(num, x);
        if(currPowerValue > n) {
            return 0;
        }

        if(t[n][num] != -1) {
            return t[n][num];
        }

        int take = solve(n-currPowerValue, num+1, x);
        int skip = solve(n, num+1, x);

        return t[n][num] = (take+skip)%M;
    }
    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n, 1, x);
    }
};
