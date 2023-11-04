/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
*/

/******************************************************** C++ **********************************************/
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;

        //<------
        for(int &x : left) {
            result = max(result, x);
        }

        //------>
        for(int &x : right) {
            result = max(result, n-x);
        }

        return result;
    }
};
