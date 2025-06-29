// Approach: Binary Search on the answer range (max element to total sum). Use greedy check to verify if mid can split array into at most k parts.
// Time Complexity: O(n * log(sum - max)), where n = size of array, because for each binary search iteration we traverse the array once.
// Space Complexity: O(1), no extra space used apart from variables.
class Solution {
public:
    // Check if we can split the array into at most k subarrays such that no subarray has a sum greater than mid
    bool check(int mid, vector<int>& arr, int k) {
        int n = arr.size();

        int count = 1; // Start with 1 subarray
        int sum   = 0; // Running sum of current subarray

        for (int i = 0; i < n; i++) {
            // If any element is greater than mid, we cannot make such a split
            if (arr[i] > mid) {
                return false;
            }

            sum += arr[i]; // Add current element to current subarray

            // If the sum exceeds mid, we need to start a new subarray
            if (sum > mid) {
                count++;
                sum = arr[i]; // Start new subarray with current element
            }
        }
        return count <= k; // Return true if we used k or fewer subarrays
    }
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();

        int low    = *max_element(arr.begin(), arr.end());        // Minimum possible max subarray sum
        int high   = accumulate(arr.begin(), arr.end(), 0);       // Maximum possible max subarray sum
        int result = 0;

        // Binary search for the minimum max subarray sum
        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(mid, arr, k)) {
                result = mid;      // Mid is a possible answer
                high   = mid - 1;  // Try to find a smaller one
            } else {
                low = mid + 1;     // Increase mid to try bigger max sum
            }
        }
        return result;
    }
};
