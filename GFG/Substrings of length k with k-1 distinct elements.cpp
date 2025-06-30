// Approach 1: Brute-force. Check every substring of length k, count the number of distinct characters using a frequency array, and check if it equals k - 1.
// Time Complexity: O(n * k), where n is the length of the string and k is the size of the window. We iterate over all substrings of length k and count distinct characters.
// Space Complexity: O(1), using a fixed-size frequency array of 26.
class Solution {
public:
    int substrCount(string& s, int k) {
        int n      = s.length();
        int result = 0;

        for (int i = 0; i <= n - k; i++) {
            vector<int> freq(26, 0); // reset frequency array for each substring

            for (int j = i; j < i + k; j++) {
                freq[s[j] - 'a']++; // count frequency of characters in current substring
            }

            int count = 0;
            for (int l = 0; l < 26; l++) {
                if (freq[l] > 0) {
                    count++; // count distinct characters
                }
            }

            if (count == k - 1) {
                result++; // valid substring
            }
        }

        return result;
    }
};


// Approach 2: Sliding window with a frequency array. Maintain a window of size 'k', track frequency of characters. When window reaches size k, check if it has exactly k-1 distinct characters.
// Time Complexity: O(n), where n is the length of the string. Each character is added and removed from the window at most once.
// Space Complexity: O(1), using a fixed-size frequency array of size 26 for lowercase English letters.
class Solution {
public:
    int substrCount(string& s, int k) {
        int n = s.length();

        vector<int> freq(26, 0);  // frequency array to store count of characters in current window
        int         distinct = 0; // number of distinct characters in current window
        int         result   = 0; // to store final count of valid substrings

        int i = 0;                // window start
        int j = 0;                // window end

        while (j < n) {
            if (freq[s[j] - 'a'] == 0) {
                distinct++;     // new character enters the window
            }
            freq[s[j] - 'a']++; // increment frequency of current character

            if (j - i + 1 > k) {
                // window size exceeded, shrink from left
                freq[s[i] - 'a']--; // remove character at position i
                if (freq[s[i] - 'a'] == 0) {
                    distinct--;     // character completely removed from window
                }
                i++;                // move window start
            }

            if (j - i + 1 == k) {
                // when window size is exactly k
                if (distinct == k - 1) {
                    result++; // valid substring
                }
            }

            j++; // expand window
        }
        return result;
    }
};
