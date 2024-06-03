//Company Tags  : AMAZON
//Leetcode Link : https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

//Approach : (Two Pointer) Simple iteration
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        int i = 0; //for s
        int j = 0; //for t

        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }            
        }

        return n-j;
    }
};
