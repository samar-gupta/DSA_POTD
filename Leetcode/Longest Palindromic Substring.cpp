/*
    Company Tags             : Accolite, Amazon, Groupon, MakeMyTrip, Microsoft, Qualcomm, Samsung, Visa, Walmart, Zoho
    Leetcode Link            : https://leetcode.com/problems/longest-palindromic-substring/
*/

/****************************************** C++ ******************************************/
//Approach 1 - Recursion + Memoization
//Memoization will help reduce time complexity for cases like - "aaaaaaaaa"
//T.C : O(n^2) - Because the AMortized Time Complexity of solve() will become 1 due to memoization.
//S.C : O(n^2)
class Solution {
public:

    int t[1001][1001];

    bool solve(string &s, int i, int j) {
        if(i >= j)
            return 1;

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s[i] == s[j]) {
            return t[i][j] = solve(s, i+1, j-1);
        }

        return t[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int maxLen = INT_MIN;
        int sp = 0;                                   //starting pointer (or) starting index

        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {

                if(solve(s, i, j) == true) {
                    if(j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};
