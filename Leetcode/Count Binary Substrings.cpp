//Company Tags  : Helix
//Leetcode Link : https://leetcode.com/problems/count-binary-substrings

//Approach (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        
        
        int result  = 0;
        int prev = 0;
        int curr = 1;
        for(int i = 1; i<n; i++) {
            if(s[i-1] != s[i]) {
                result += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        }
        
        return result + min(prev, curr);
    }
};
