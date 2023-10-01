/*
    Company Tags                : Zappos, MentorGraphics
    Leetcode Link               : https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

/******************************************************** C++ ******************************************************************/ 
// Approach-1 (Simple traversal)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] != ' ') {
                
                int j = i;
                
                while( j < n && s[j] != ' ') {
                    j++;
                }
                
                reverse(s.begin() + i, s.begin() + j);
                
                i = j;
            }
            
        }
        
        return s;
    }
};

// Approach-2 (Using stringstream in C++)
class Solution {
public:
    string reverseWords(string &s) {
        stringstream ss(s);

        string result = "";
        string token = "";

        while(ss >> token) {
            reverse(begin(token), end(token));
            result += token + " ";
        }

        return result.substr(0, result.length()-1);
    }
};
