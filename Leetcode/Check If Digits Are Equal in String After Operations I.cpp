//Leetcode Link : https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

//Approach (simple traverse and check)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        while(n > 2) {

            for(int i = 0; i < n-1; i++) {
                s[i] = (((s[i] - '0') + (s[i+1] - '0')) % 10) + '0';
            }

            n--;
        }

        return s[0] == s[1];
    }
};
