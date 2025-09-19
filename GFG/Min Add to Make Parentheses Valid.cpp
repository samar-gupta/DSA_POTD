//Approach-1 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int open = 0, close = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                if (open > 0) 
                    open--;
                else
                    close++;
            }
            
        }
        
        return open + close;
    }
};
