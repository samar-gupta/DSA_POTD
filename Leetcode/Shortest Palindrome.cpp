//Company Tags  : GOOGLE
//Leetcode Link : https://leetcode.com/problems/shortest-palindrome

//Approach (Using simple substring check for Prefix and Suffix)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        //T.C : O(n^2)
        //S.C : O(n)
        for(int i = 0; i < s.length(); i++) {

            if(!memcmp(s.c_str(), rev.c_str() + i, s.length()-i)) { //prefix in s == suffix in rev
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }
};


//Approach (Using LPS in KMP)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    // Function to compute the LPS (Longest Proper Prefix which is also Suffix) array
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix
    
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; //You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(), 0); //O(n)
        computeLPS(temp, LPS);

        int longestLPSLength = LPS[temp.length()-1]; //temp.back();

        string culprit = rev.substr(0, s.length() - longestLPSLength); //O(n)

        return culprit + s;
    }
};

