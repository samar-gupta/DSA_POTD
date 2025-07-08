// Approach 1: Brute-force – For each element, scan to the right until you find one with strictly higher frequency.
// Time Complexity: O(n²) – two nested loops in the worst case.
// Space Complexity: O(n) – for the frequency map (output vector not counted).
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int                     n = arr.size();
        vector<int>             result(n, -1);
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;                                            // build frequency map
        }
        // for each position, scan to its right for next with higher freq
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (freq[arr[j]] > freq[arr[i]]) {                // found higher-frequency
                    result[i] = arr[j];
                    break;
                }
            }
        }
        return result;
    }
};


// Approach 2: O(n) stack – use a stack of indices to track “waiting” positions, resolving when a higher-freq arrives.
// Time Complexity: O(n) – each index is pushed/popped at most once.
// Space Complexity: O(n) – for the frequency map and the stack.
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int                     n = arr.size();
        vector<int>             result(n, -1);
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        stack<int> st;                                           // will hold indices

        // traverse from left to right
        for (int i = 0; i < n; i++) {
            // resolve any stack tops whose freq < current freq
            while (!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
