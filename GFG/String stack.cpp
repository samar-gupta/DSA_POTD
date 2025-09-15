//Approach-1 : 
//T.C : O(n + m)
//S.C : O(1)
class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int i = pat.size() - 1, j = tar.size() - 1;
        if(j > i) return false;
    
        while (i >= 0 and j >= 0) {
            
            if (pat[i] != tar[j]) i -= 2;
            else {
                i--;
                j--;
            }
        }
        
        return j < 0;
    }
};
