class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                swap(arr[i], arr[idx]);
                idx++;
            }
        }
        
        sort(arr.begin(), arr.begin() + idx, greater<int>());
        sort(arr.begin() + idx, arr.end());
    }
};
