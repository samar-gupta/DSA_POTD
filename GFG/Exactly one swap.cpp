// Approach 1: Brute‐force all possible one‐swap variations by swapping each pair (i, j) and using a hash set to count unique results.
// Time Complexity: O(n³) in the worst case – O(n²) swaps × O(n) string‐hash/compare per insertion.
// Space Complexity: O(n³) – up to O(n²) distinct strings of length n stored in the set.
class Solution {
public:
    int countStrings(string& s) {
        int n = s.length();                              // length of the string

        unordered_set<string> set;                       // to store unique strings after one swap

        // Try every pair (i, j) with i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(s[i], s[j]);                        // swap chars at i and j
                set.insert(s);                           // record the new string (duplicates are auto‐ignored)
                swap(s[i], s[j]);                        // swap back to restore original
            }
        }

        return set.size();                               // number of distinct one‐swap strings
    }
};


// Approach 2: Count distinct strings by tracking character frequencies. For each index i,
// subtract number of characters seen so far that are equal to s[i] to count how many swaps
// with different characters are possible. If any character appears more than once, add 1 more
// to include the case where a swap results in the same string.
// Time Complexity: O(n) – Single pass for counting + fixed 26-char check.
// Space Complexity: O(1) – Frequency array of size 26.
class Solution {
public:
    int countStrings(string& s) {
        int n = s.length();

        vector<int> mp(26, 0);         // frequency array for lowercase letters
        int         result = 0;

        for (int i = 0; i < n; i++) {
            result += (i - mp[s[i] - 'a']);   // count swaps with different chars seen so far
            mp[s[i] - 'a']++;                 // increment frequency of current character
        }

        for (int i = 0; i < 26; i++) {
            if (mp[i] > 1) {         // check if any character has duplicate
                result++;            // if yes, add one for swap that returns same string
                break;
            }
        }

        return result;
    }
};
