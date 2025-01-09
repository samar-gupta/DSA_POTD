//Approach : (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();   
        int left = 0, right = 0;   // Two pointers to represent the sliding window
        int sum = 0;               // Sum of the current window

        // Iterate while the `right` pointer is within bounds
        while (right <= n) {
            // If the current window's sum matches the target, return 1-based indices
            if (sum == target) {
                return {left + 1, right};  // 1-based index
            }
            // Expand the window by moving the `right` pointer
            else if (sum < target) {
                if (right < n) {          // Avoid out-of-bounds access
                    sum += arr[right];
                }
                right++;                   // Move the right pointer forward
            }
            // Shrink the window by moving the `left` pointer
            else if (sum > target) {
                sum -= arr[left];
                left++;                    // Move the left pointer forward
            }
        }
        // Return {-1} if no subarray with the given sum is found
        return {-1};
    }
};
