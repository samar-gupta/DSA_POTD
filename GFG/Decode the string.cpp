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
