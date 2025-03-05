//Leetcode Link : https://leetcode.com/problems/count-total-number-of-colored-cells

//Approach-1 (Using simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long coloredCells(int n) {
        int t = 1;
        long long cells = 1;

        while(t <= n) {
            cells += (4 * (t-1));
            t++;
        }

        return cells;
    }
};


//Approach-2 (Using Mathematical derivation)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    long long coloredCells(int n) {
        return 1 + (2 * (long long)(n-1) * n);
    }
};
