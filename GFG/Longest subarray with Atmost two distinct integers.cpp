// Approach: Use a sliding window with two pointers (i, j) and an unordered_map to track frequencies. Expand j until we have more than two distinct elements, then shrink i until we’re back to at most two.
// Time Complexity: O(n) — each element is added and removed at most once.
// Space Complexity: O(1) — the map holds at most 2 keys.
class Solution {
public:
    int totalElements(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;

        int i      = 0;          // left boundary of window
        int j      = 0;          // right boundary of window
        int result = 0;          // best window size seen

        while (j < n) {
            // include arr[j] into the window
            mp[arr[j]]++;

            // if more than two distinct numbers, shrink from left
            while (mp.size() > 2) {
                mp[arr[i]]--;            // decrement freq of arr[i]
                if (mp[arr[i]] == 0) {   // if freq is zero, remove key
                    mp.erase(arr[i]);
                }
                i++;                     // move left boundary right
            }

            // window [i..j] is valid, update result
            result = max(result, j - i + 1);
            j++;                        // expand window to the right
        }

        return result;
    }
};
