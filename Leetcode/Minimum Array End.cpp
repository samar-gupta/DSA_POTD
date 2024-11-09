//Leetcode Link : https://leetcode.com/problems/minimum-array-end/description/

//Approach - Simple using AND and OR
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;

        for(int i = 1; i < n; i++) {

            //num+1
            num = (num+1) | x;
            
        }

        return num;
    }
};
