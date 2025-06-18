// Approach: Use recursive backtracking to explore all possible partitions. For each index, expand and include substrings that are palindromes, then recursively partition the rest.
// Time Complexity: O(2^n * n) – At each index, we make 2 choices (cut or not) and check for palindrome in O(n) time.
// Space Complexity: O(n) – for recursion stack and current path storage.
class Solution {
public:
    // Check if s[l..r] is a palindrome
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false; // Return false if characters at both ends don't match
            }
            l++;              // Move left pointer forward
            r--;              // Move right pointer backward
        }
        return true;          // All characters matched, hence it's a palindrome
    }

    // Recursive backtracking to explore all palindromic partitions
    void backtrack(int idx,
                   string& s,
                   vector<string>& curr,
                   vector<vector<string> >& result) {
        if (idx == s.size()) {
            result.push_back(curr); // Add current partition to result if end of string is reached
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            // Check if s[idx..i] is a palindrome
            if (isPalindrome(s, idx, i)) {
                // If yes, add it to the current path
                curr.push_back(s.substr(idx, i - idx + 1));

                // Recurse for the remaining substring
                backtrack(i + 1, s, curr, result);

                // Backtrack: remove last added substring and try next possibility
                curr.pop_back();
            }
        }
    }

    // Entry function to initiate backtracking
    vector<vector<string> > palinParts(string& s) {
        vector<vector<string> > result; // Final result of all partitions
        vector<string>          curr;   // Current partition path

        backtrack(0, s, curr, result);  // Start from index 0
        return result;
    }
};
