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
