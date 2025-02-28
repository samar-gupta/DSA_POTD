class Solution {
  public:
    bool isOperator(const string& s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int apply(int a, int b, const string& op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b; // Integer division rounds toward zero
        return 0;
    }
    
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        
        for (string ch : arr) {
            if (isOperator(ch)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = apply(a, b, ch);
                st.push(res);
            } else {
                st.push(stoi(ch)); // Convert string to integer
            }
        }
        
        return st.top();
    }
};
