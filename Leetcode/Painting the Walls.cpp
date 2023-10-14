/*
    Company Tags                : GOOGLE
    Letcode Link                : https://leetcode.com/problems/painting-the-walls/
*/

/********************************************* C++ *********************************************/
//Company Tags : GOOGLE
//Approach-1 (Recursion + Memo)
//T.C : O(n^2) - we will visit at max n^2 states
class Solution {
public:
    int n;
    int t[501][501];
    
    int solve(int idx, int remaining, vector<int>& cost, vector<int>& time) {

        if(remaining <= 0)
            return 0;              // no cost

        if(idx >= n) {
            return 1e9;           // invalid case
        }

        if(t[idx][remaining] != -1) {
            return t[idx][remaining];
        }

        int paint_idx = cost[idx] + solve(idx+1, remaining - 1 - time[idx], cost, time);
        int not_paint_idx = solve(idx+1, remaining, cost, time);

        return t[idx][remaining] = min(paint_idx, not_paint_idx);
    } 

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, cost, time);
    }
};
