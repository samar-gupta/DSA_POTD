class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int mid = n / 2;
        
        sort(arr.begin(), arr.begin() + mid);
        sort(arr.begin() + mid, arr.end());
        
        int ans = 0;
        int j = mid;
        
        for (int i = 0; i < mid; ++i) {
            while (j < n && arr[i] >= 5LL * arr[j]) {
                ++j;
            }
            ans += (j - mid);
        }
        return ans;
    }
};
