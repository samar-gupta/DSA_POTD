//Company Tags   : META
//Leetcode Link  : https://leetcode.com/problems/valid-parenthesis-string/

//T.C : O(n)
//S.C :O(1)
//NOTE : We can easily combine both for loops in just a single for loop. I have written them separately for sake of simplicity and understanding
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        
        //Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }
                
            if (open < 0) {
                return false;
            }
        }

        //Right to Left - Check CLose Brackets
        for (int i = n - 1; i >= 0; i--) {
            
            if (s[i] == ')' || s[i] == '*') {
                close++;
            } else {
                close--;
            }
            
            
            if (close < 0) {
                return false;
            }
        }
        
        return true;
    }
};
