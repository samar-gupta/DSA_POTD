class Solution {
  public:
    
    string str;
    stack<char>st;
    
    void append(char x) {
        // append x into document
        str+=x;
    }

    void undo() {
        // undo last change
        char ch=str[str.size()-1];
        str.pop_back();
        st.push(ch);
    }

    void redo() {
        // redo changes
        str+=st.top();
        st.pop();
    }

    string read() {
        // read the document
        return str;
    }
};
