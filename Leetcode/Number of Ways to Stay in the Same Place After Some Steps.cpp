/*
    Company Tags                : GOOGLE, META
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
*/


/************************************************ C++ ************************************************/
//Approach-1 (Using Recursion + Memo - Top Down)
//T.C : O(steps * min(steps, arrLen))
class Solution {
public:
    int n;
    int t[501][501];
    int MOD = 1e9+7;
    int solve(int idx, int steps) {

        if(idx < 0 || idx >= n)
            return 0;

        if(steps == 0) {
            return idx == 0;                     // if idx and steps both == 0 return 1 ,else return 0
        }

        if(t[idx][steps] != -1)
            return t[idx][steps];

        int result = solve(idx+1, steps-1) % MOD;                // RIGHT
        result = (result + solve(idx-1, steps-1)) % MOD;        // LEFT
        result = (result + solve(idx, steps-1)) % MOD;         // STAY
        return t[idx][steps] = result;
    }

    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps/2+1);              // Note that furthest we can go is by only making moves to the right, but we can go to right by "steps" moves. Thus, we can safely perform arrLen = min(arrLen, steps)  // Also if you notice, you can only move away from 0 in the array by at max steps/2 to come back to 0 . So, we can also doarrLen = min(arrLen, (steps+1)/2); //(steps+1)/2 takes care of Odd case as well.

        n = arrLen;
        memset(t, -1, sizeof(t));
        return solve(0, steps);
    }
};
