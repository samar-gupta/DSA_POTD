class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        unordered_set<int> st(arr.begin(), arr.end());

        int ans = 0;

        for (int x : arr) {
            if (!st.count(x - 1))
                ans++;
        }

        return ans;
    }
};
