//Approach:
//T.C -> O( logn )  
//S.C -> O(1)
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        // Step 1: Initialize variables
        int n = arr.size();        // Size of the array
        int low = 0, high = n - 1; // Search range for binary search

        // Step 2: Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;   // Find the middle index
            int missing = arr[mid] - (mid + 1); // Calculate number of missing numbers up to arr[mid]
            
            if (missing < k) {
                // If the number of missing numbers so far is less than k,
                // it means the k-th missing number is to the right.
                low = mid + 1;
            } else {
                // Otherwise, the k-th missing number is to the left or at mid.
                high = mid - 1;
            }
        }

        // Step 3: Return the k-th missing number
        // After the loop, `high` points to the last position where the missing numbers are < k.
        // The k-th missing number is `k + high + 1` because:
        // - `k` is the target missing number count
        // - `high + 1` gives the actual index offset in the missing sequence.
        return k + high + 1;
    }
};



//old
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int left = 0;
        int right = arr.size() - 1;
        int ind = -1;

        // Perform binary search to find the largest index where the number of missing elements so far is less than k
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the mid-point to avoid overflow
            if (arr[mid] - mid - 1 < k) { // Check if the number of missing elements before arr[mid] is less than k
                ind = mid; // Update the index
                left = mid + 1; // Narrow the search to the right half
            } else {
                right = mid - 1; // Narrow the search to the left half
            }
        }

        // If no valid index is found, return k (kth missing lies before the start of the array)
        if (ind == -1)
            return k;

        // Otherwise, calculate the kth missing element using the found index
        return k + ind + 1;
    }
};
