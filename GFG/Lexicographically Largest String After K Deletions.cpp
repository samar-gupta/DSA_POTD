// Approach: Use a greedy stack-based method to remove smaller preceding characters when a larger character is encountered, ensuring the remaining string of length n-k is lexicographically maximal.
// Time Complexity: O(n) where n = s.length(), since each character is pushed and popped at most once.
// Space Complexity: O(n) for the additional result string.
class Solution {
public:
    string maxSubseq(string& s, int k) {
        int    n        = s.length();
        int    toRemove = k;         // number of characters we still need to remove
        string result   = "";        // acts like a stack to build the answer

        for (int i = 0; i < n; i++) {
            // while we can remove characters, and the current character s[i] is greater
            // than the last in result, pop to make result lexicographically larger
            while (!result.empty() && toRemove > 0 && s[i] > result.back()) {
                result.pop_back();
                toRemove--;
            }
            result.push_back(s[i]); // include current character
        }

        // if we haven't removed enough (e.g., string was non-decreasing), trim from the end
        result.resize(n - k);
        return result;
    }
};
