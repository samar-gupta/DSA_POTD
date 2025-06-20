// Approach 1: Sort the array and greedily form consecutive groups of size k by marking used elements.
// Time Complexity: O(n log n + n·k) due to sorting and scanning for each group, which is O(n log n) when k ≪ n.
// Space Complexity: O(1) extra space (in-place marking with -1), aside from the input array.
class Solution {
public:
    bool validgroup(vector<int>& arr, int k) {
        int n = arr.size();                   // total number of balls

        sort(arr.begin(), arr.end());         // bring consecutive numbers together

        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) {                // already used in a previous group
                continue;
            }

            int curr  = arr[i];               // the next expected number in the group
            int count = 0;                    // how many balls have been added to the current group

            for (int j = i; j < n; j++) {
                if (arr[j] == curr) {         // found the next consecutive ball
                    curr++;                   // expect the next number in sequence
                    count++;                  // one more ball added to this group
                    arr[j] = -1;              // mark this ball as used
                }

                if (count == k) {              // the group is complete
                    break;
                }
            }

            if (count != k) {                  // could not form a full group of size k
                return false;
            }
        }
        return true;                          // all balls successfully grouped
    }
};


// Approach 2: Use a frequency map to count occurrences, then for each smallest available number greedily form consecutive sequences by decrementing counts.
// Time Complexity: O(n log n + m·k) where n = arr.size(), m = number of unique keys (m ≤ n), overall O(n log n + n) ≈ O(n log n).
// Space Complexity: O(n) extra space for the map.
class Solution {
public:
    bool validgroup(vector<int>& arr, int k) {
        int           n = arr.size();
        map<int, int> mp;                     // frequency map

        // count each value
        for (int val : arr) {
            mp[val]++;
        }

        // iterate in ascending order of values
        for (auto p : mp) {
            int val  = p.first;              // current value
            int freq = p.second;             // how many sequences start here

            if (freq == 0) {                 // already used up
                continue;
            }

            // try to build freq sequences of length k starting at val
            for (int i = 1; i < k; i++) {
                int nextVal = val + i;

                // if not enough nextVal to pair with all freq sequences, fail
                if (mp[nextVal] < freq) {
                    return false;
                }

                // consume freq of nextVal
                mp[nextVal] -= freq;
            }
        }
        return true;                         // all sequences formed successfully
    }
};
