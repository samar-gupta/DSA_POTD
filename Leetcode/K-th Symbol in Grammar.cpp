/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Cw7A8YU0WjY
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/k-th-symbol-in-grammar
*/

/************************************************ C++ ************************************************/
//(Using Recursion)
//T.C : O(N)
//S.C : O(N) Recursion Stack space
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1)
            return 0;

        int length = pow(2, n-1);
        int mid = length/2;

        if(k <= mid) {
            return kthGrammar(n-1, k);              // half is same as previous row, so ans can be found in previous row for k
        } else {
            return !kthGrammar(n-1, k-mid);       // ! or  1 - solve(n-1, k-mid)  as  (1 - 0 = 1) and (1 - 1 = 0)
        }
    }
};
