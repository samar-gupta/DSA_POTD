class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        // XOR of first window
        int curr = 0;
        for (int i = 0; i < k; i++) {
            curr ^= arr[i];
        }
        int result = curr;
        
        // Slide the window
        for (int i = k; i < n; i++) {
            curr ^= arr[i-k];   // remove left element
            curr ^= arr[i];     // add new right element
            result = max(result, curr);
        }
        
        return result;
    }
};
