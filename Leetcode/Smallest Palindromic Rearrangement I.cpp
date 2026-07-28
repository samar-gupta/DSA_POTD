//Leetcode Link : https://leetcode.com/problems/smallest-palindromic-rearrangement-i/

//Approach (Split in half , Sort and form palindrome)
//T.C : O(n log n)
//S.C : O(1) (ignoring the space taken for sorting internally)
class Solution {
public:
    string smallestPalindrome(string s) {
        int n   = s.length();
        int mid = n/2;

        sort(s.begin(), s.begin() + mid); //note : mid is not included i.e. [begin, mid)

        for (int i = 0; i < mid; i++) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};
