class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        // Declare a stack to store the opening brackets
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
  
            // Check if the character is an opening bracket
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
  
            else {
  
                // If it's a closing bracket, check if the stack is non-empty
                // and if the top of the stack is a matching opening bracket
                if (!st.empty() && ((st.top() == '(' && s[i] == ')') ||
                                    (st.top() == '{' && s[i] == '}') ||
                                    (st.top() == '[' && s[i] == ']'))) {
  
                      // Pop the matching opening bracket
                    st.pop();
                } else {
  
                    // Unmatched closing bracket
                    return false;
                }
            }
        }
  
        // If stack is empty, return true (balanced), otherwise false
        return st.empty();
    }
};
