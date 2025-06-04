//Leetcode Link : https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i

//Approach-1 (trying at every index to find best substring)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if( numFriends == 1)
            return word;

        string result;

        int longestPossible = n - (numFriends - 1);

        for(int i = 0; i < n; i++) {
            int canTakeLength = min(longestPossible, n-i);

            result = max(result, word.substr(i, canTakeLength));
        }

        return result;
    }
};
