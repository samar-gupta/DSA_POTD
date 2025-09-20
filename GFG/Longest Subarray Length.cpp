//Approach-1 :
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Previous greater
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next greater
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int len = right[i] - left[i] - 1;
            if (arr[i] <= len)
                ans = max(ans, len);
        }
        return ans;
    }
};
