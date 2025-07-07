// Approach 1: Brute-force – For each element, check the next n−1 elements circularly to find the next bigger element.
// Time Complexity: O(n²) – Outer loop runs n times, and for each i, inner loop can run up to n times in worst case.
// Space Complexity: O(1) – No extra space used apart from the output vector.
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();                       // Size of the array

        vector<int> result(n, -1);                // Result initialized with -1s (next greater not found by default)

        // Iterate for all the elements of the array
        for (int i = 0; i < n; i++) {             // Fix index i
            for (int j = 1; j < n; j++) {         // Check next n−1 elements circularly
                // Checking for next greater element
                if (arr[i] < arr[(i + j) % n]) {  // If current element is smaller than next circular element
                    result[i] = arr[(i + j) % n]; // Assign the next greater
                    break;                        // No need to check further
                }
            }
        }

        return result;                            // Return the result
    }
};


// Approach 2: O(n) monotonic stack – traverse twice, using a stack of indices to assign next bigger elements as they arrive.
// Time Complexity: O(n) – each index is pushed and popped at most once.
// Space Complexity: O(n) – auxiliary stack for indices.
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int         n = arr.size();             // Size of the array
        vector<int> result(n, -1);              // Result initialized to -1s
        stack<int>  st;                         // Stack to store indices of waiting elements

        for (int i = 0; i < 2 * n; i++) {       // Traverse twice for circularity
            int idx = i % n;                    // Actual index in arr
            int num = arr[idx];                 // Current number

            // While current num is bigger than arr at the top index
            while (!st.empty() && num > arr[st.top()]) {
                result[st.top()] = num;         // Assign it as the next greater
                st.pop();                       // Remove that index
            }

            if (i < n) {                        // Only push original indices on first pass
                st.push(idx);                   // Add index to stack
            }
        }
        return result;                          // Return filled results
    }
};
