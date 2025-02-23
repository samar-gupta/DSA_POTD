class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1); // Initialize all elements as -1
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return ans;
    }
};
