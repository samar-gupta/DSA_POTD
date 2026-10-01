//Leetcode Link : https://leetcode.com/problems/valid-parentheses/description/

//Approach (Using Stack - you can use a string as well)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch:s) {
            if (ch == '(')
                st.push(')');
            else if (ch == '{')
                st.push('}');
            else if (ch == '[')
                st.push(']');
            else if (st.empty() || st.top() != ch)
                return false;
            else {
                st.pop();
            }
        }

        return st.empty();
    }
};



//Approach :
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(') {
                    return false;
                }
                if (ch == ']' && top != '[') {
                    return false;
                }
                if (ch == '}' && top != '{') {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
