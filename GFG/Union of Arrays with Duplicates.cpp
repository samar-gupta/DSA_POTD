class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>st(a.begin(),a.end());
        st.insert(b.begin(),b.end());
        return vector<int>(st.begin(),st.end());
    }
};


// old
class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        a.insert(a.end(),b.begin(),b.end());
        unordered_set<int>st(a.begin(),a.end());
        return st.size();
    }
};
