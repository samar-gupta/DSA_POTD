//Leetcode Link : https://leetcode.com/classic/problems/check-if-one-string-swap-can-make-strings-equal/

//Approach-1 : 
//T.C :  O(n)   //We traverse the string once, making it linear in complexity.
//S.C : ~ O(1)   //We only use a few integer variables (first, second, count), so the space remains constant
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff.push_back(i);
            if (diff.size() > 2) return false;
        }

        return diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};
