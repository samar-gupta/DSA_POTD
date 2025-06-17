// Approach: Sort the array, then for each element arr[i], assume it's the smallest allowed value. Use upper_bound to find the last pile that can remain with value ≤ arr[i]+k. Remove coins from all piles before i and from those after idx that exceed arr[i]+k.
// Time Complexity: O(n log n) - due to sorting and binary search for each element.
// Space Complexity: O(n) - for storing prefix sums.
class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();

        // Sort the array to process piles in increasing order
        sort(arr.begin(), arr.end());

        // Compute prefix sum array to calculate sum in range efficiently
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int result = INT_MAX; // Store minimum coins to remove
        int prev   = 0;       // Sum of coins to be removed from piles before index i

        for (int i = 0; i < n; i++) {
            // Find index of first pile > arr[i] + k using upper_bound
            int idx = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();

            if (i > 0) {
                prev = prefix[i - 1]; // Coins to remove from all piles before i
            }

            // Coins to remove from all piles beyond idx that are > arr[i] + k
            int totalToRemove = prev + prefix[n - 1] - prefix[idx - 1] - (arr[i] + k) * (n - idx);

            // Update result with minimum coins to remove
            result = min(result, totalToRemove);
        }
        return result;
    }
};
