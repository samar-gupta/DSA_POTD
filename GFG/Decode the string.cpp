//Approach-1 : 
class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char> st;
        
        for (char ch : s) {
            if (ch != ']') st.push(ch);
            else {
                
                string temp = "";
                while (!st.empty() && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                
                reverse(temp.begin(), temp.end());
                st.pop();  //removing opening bracket '['
                string num = "";
                
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }
                
                int number = stoi(num);
                string repeat = "";
                for (int i = 0; i < number; i++) repeat += temp;
                for (char c : repeat) st.push(c);
            }
        }
        
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};



//old
class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> countStack;         //stack for storing numbers
        stack<string> resultStack;     //stack for storing string
        int i = 0, num = 0;
        string curr = "";

        while (i < s.length()) {
            if (isdigit(s[i])) {
                num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                countStack.push(num);
            } 
            else if (s[i] == '[') {
                resultStack.push(curr);
                curr = "";
                i++;
            } 
            else if (s[i] == ']') {
                int n = countStack.top();
                countStack.pop();
                string temp = resultStack.top();
                resultStack.pop();
                for (int j = 0; j < n; j++) {
                    temp += curr;
                }
                curr = temp;
                i++;
            } 
            else {
                curr += s[i];
                i++;
            }
        }
        return curr;
    }
};
