// Approach:
// - We are trying to find the largest divisible subset in the given array.
// - We use a backtracking approach where at each index, we make two choices:
//   1) Include the current element in the subset if it is divisible by the previous one.
//   2) Skip the current element.
// - If we include an element, we add it to a temporary list (`temp`) and proceed to the next index recursively.
// - Once all indices are processed, we check if the current subset (`temp`) is larger (or lexicographically greater if sizes are equal) than the stored result (`result`), and update `result` if necessary.

// Time Complexity:
// - Sorting the array takes O(n log n). The recursion explores all subsets, and for each element, we either include it or not, resulting in O(2^n) calls.
// - So, the total time complexity is O(n log n + 2^n) due to sorting and the recursive calls.

// Space Complexity:
// - The space complexity is O(n) for the recursion stack and the temporary storage (`temp`), which holds a subset at any given point.

class Solution {
public:
    // Helper function for recursion with backtracking
    void solve(int idx, vector<int>& arr, vector<int>& result, vector<int>& temp, int prev) {
        if (idx >= arr.size()) {
            // replace if strictly larger, or same size but lexicographically greater
            if (temp.size() > result.size() ||
                (temp.size() == result.size() && temp > result)) {
                result = temp;
            }
            return;
        }

        // include arr[idx] if divisible
        if (prev == -1 || arr[idx] % prev == 0) {
            temp.push_back(arr[idx]);                    // Add the element to temp
            solve(idx + 1, arr, result, temp, arr[idx]); // Recurse for the next element
            temp.pop_back();                             // Backtrack, remove the element from temp
        }

        // skip arr[idx]
        solve(idx + 1, arr, result, temp, prev);  // Recurse for the next element without including arr[idx]
    }
    // Function to return the largest divisible subset
    vector<int> largestSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());    // Sort the array to ensure lexicographical order
        vector<int> result, temp;        // To store the largest subset and temporary subset during recursion
        solve(0, arr, result, temp, -1); // Start the recursive function
        return result;                   // Return the largest subset found
    }
};



// Approach:
// - This solution uses dynamic programming (DP) with memoization to find the largest divisible subset from the given array.
// - At each index, we make two choices:
//   1) Include the current element in the subset if it is divisible by the previous element in the subset.
//   2) Skip the current element and move to the next index.
// - The `dp` table stores the best subset for every state `(idx, prev_idx)` where `idx` is the current element's index and `prev_idx` is the last included index.
// - The function is recursively called with two options (including or skipping the current element), and the larger subset (or lexicographically larger if sizes are the same) is stored in the memoization table.

// Time Complexity:
// - Sorting the array takes O(n log n). The recursion explores all possible subsets, and for each element, we either include it or skip it, leading to O(2^n) calls.
// - The total time complexity is O(n log n + 2^n) due to sorting and the recursive calls.

// Space Complexity:
// - The space complexity is O(n^2) because the memoization table `dp` has dimensions `n x (n + 1)`, and the recursion stack uses O(n) space.
//   Therefore, the overall space complexity is O(n^2).

class Solution {
public:
    // Memoization table to store the best subsets
    vector<vector<vector<int>>> dp;

    // Helper function for recursion with memoization
    vector<int> solve(int idx, vector<int>& arr, int prev_idx) {
        // Base case: if idx is out of bounds, return an empty vector
        if (idx == arr.size()) {
            return {};
        }

        // If already computed, return the result from dp
        if (dp[idx][prev_idx + 1].size() > 0) {
            return dp[idx][prev_idx + 1];
        }

        // Option 1: Take arr[idx] if divisible by arr[prev_idx]
        vector<int> taken;
        if (prev_idx == -1 || arr[idx] % arr[prev_idx] == 0) {
            taken = solve(idx + 1, arr, idx);      // Take current element
            taken.insert(taken.begin(), arr[idx]); // Add current element to the result
        }

        // Option 2: Skip arr[idx]
        vector<int> not_take = solve(idx + 1, arr, prev_idx);  // Skip current element

        // Compare the result from both options and store the larger one
        vector<int> result = (not_take.size() > taken.size() || (not_take.size() == taken.size() && not_take > taken))
                              ? not_take : taken;

        // Memoize the result and return
        return dp[idx][prev_idx + 1] = result;
    }
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());  // Sort the array to ensure lexicographical order

        // Initialize dp table once in the function
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n + 1));

        // Start the recursion with no previous element (-1) and from index 0
        return solve(0, arr, -1);
    }
};
