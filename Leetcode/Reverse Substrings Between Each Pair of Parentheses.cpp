//Company Tags  : META, AMAZON
//Leetcode Link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openeBracket; //You can use a vector also as stack
        string result;
        for (char currentChar : s) {
            if (currentChar == '(') {
                openeBracket.push(result.length());
            } else if (currentChar == ')') {
                int start = openeBracket.top();
                openeBracket.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += currentChar;
            }
        }
        return result;
    }
};


//Approach-2 (Linear Approach)
//T.C : O(n) ~ O(n + n) Two Pass
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        int direction = 1; //Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};
