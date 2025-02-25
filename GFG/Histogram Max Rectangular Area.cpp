class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<long long> l(n), r(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            r[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long res=0;
        for(int i=0; i<n; i++)
            res = max(res, arr[i] * (r[i]-l[i]-1));
        return res;
    }
};
