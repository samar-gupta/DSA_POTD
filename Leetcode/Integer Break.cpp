/*
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/integer-break/
*/

/****************************************************** C++ ***********************************************************/
//Approach-1 (Recursion  + Memo)
//T.C : O(n^2) - Because we visit at max n states and at each state we run a for loop from 1 to n-1
//S.C : O(59) ~ O(1)

class Solution {
public:
    int t[59];
    int solve(int n) {

        if(n == 1) return 1;

        if(t[n] != -1)
            return t[n];

        int result = INT_MIN;

        for(int i = 1; i<=n-1; i++) {

            int prod = i * max(n-i, solve(n-i));

            result = max(result, prod);
        }

        return t[n] = result;
    }

    int integerBreak(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
