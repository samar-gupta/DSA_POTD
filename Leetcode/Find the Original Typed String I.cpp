//Leetcode Link : https://leetcode.com/problems/find-the-original-typed-string-i

//Approach (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;

        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1])
                count++;
        }

        return count+1; //+1 for when Alice does no long press
    }
};
