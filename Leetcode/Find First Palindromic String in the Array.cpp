//Leetcode Link     : https://leetcode.com/problems/find-first-palindromic-string-in-the-array

//Approach-1 : 2 Pointer (at first and last index)
//Approach-2 : Reverse the string and check (using temp)

//Approach-3 (creating a reversed string)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(n) - Creating a reversed string
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(string &word : words) {
            if(word == string(rbegin(word), rend(word))) {
                return word;
            }
        }
        
        return "";
        
    }
};

//Approach-4 (using equal)
//T.C : O(m*n) - m = number of words, n = max length length of words
//S.C : O(1)
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(string &word : words) {
            int n = word.size();
            if(equal(word.begin(), word.begin() + n/2, word.rbegin())) {
                return word;
            }
        }

        return "";
    }
};
