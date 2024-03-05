//Leetcode Link  : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

//Using simple 2 Pointers
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        
        int i = 0, j = n-1;
        
        while(i < j && s[i] == s[j]) {
            char ch = s[i];               //s[j]
            
            while(i < j && s[i] == ch) {
                i++;
            }
            
            while(j >= i && s[j] == ch) {
                j--;
            }
        }
        
        return j-i+1;
    }
};
