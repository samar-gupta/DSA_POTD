class Solution {
  public:
  
    int min;
    stack<int> st; 
    
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if (st.empty()) {
            min = x;
        } else if (x <= min) {
            st.push(min);
            min = x;
        }
        st.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if (st.empty()) 
            return;
        int tmp = st.top();
        st.pop();
        if (tmp == min && !st.empty()) {
            min = st.top();
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if (st.empty()) 
            return -1;
        return st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if (st.empty()) 
            return -1;
        return min;
    }
};
