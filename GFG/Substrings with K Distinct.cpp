// Approach 1: Brute-force using nested loops. For each starting index i, we expand the substring to the right and maintain a frequency array to track distinct characters. If the number of distinct characters becomes exactly k, we count it. If it exceeds k, we break early.
// Time Complexity: O(n^2) in the worst case due to nested loops, where n is the length of the string.
// Space Complexity: O(1) because we use a fixed-size frequency array of size 26.
class Solution {
public:
    int countSubstr(string& s, int k) {
        int n      = s.length();
        int result = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);     // frequency array to store character counts
            int         distinctCnt = 0; // number of distinct characters in current window

            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a'] == 0) {
                    distinctCnt++;  // new distinct character found
                }
                freq[s[j] - 'a']++; // increment frequency of current character

                if (distinctCnt == k) {
                    result++; // valid substring with exactly k distinct characters
                } else if (distinctCnt > k) {
                    break;    // more than k distinct characters, break early
                }
            }
        }
        return result;
    }
};


// Approach 2: Use sliding window to count substrings with at most K distinct characters. To get exactly K distinct, we subtract countAtMostK(s, k) - countAtMostK(s, k - 1).
// Time Complexity: O(n), where n is the length of the string. Each character is processed at most twice (once by j and once by i).
// Space Complexity: O(1) since at most 26 lowercase letters are stored in the hashmap.
class Solution {
public:

    int countAtMostK(string& s, int k) {
        int n = s.length();
        unordered_map<char, int> mp; // frequency map
        int i      = 0;              // left pointer
        int j      = 0;              // right pointer
        int result = 0;              // final answer

        while (j < n) {
            mp[s[j]]++; // include current character

            while (mp.size() > k) {
                mp[s[i]]--;         // shrink from the left
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]); // remove completely if frequency is 0
                }
                i++;
            }

            result += j - i + 1; // count valid substrings in current window
            j++;
        }
        return result;
    }
    int countSubstr(string& s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1); // exactly k = atMost(k) - atMost(k-1)
    }
};


// Approach 3: Sliding Window with Fixed-Size Array. Count substrings with at most K distinct characters using a frequency array of size 26. To get substrings with exactly K distinct characters, subtract countAtMostK(s, k) - countAtMostK(s, k - 1).
// Time Complexity: O(n), where n is the length of the string. Each character is processed at most twice (once by i and once by j).
// Space Complexity: O(1), using a fixed-size array of size 26 for lowercase characters.
class Solution {
public:

    int countAtMostK(string& s, int k) {
        int n           = s.length(); // Length of the string
        int mp[26]      = { 0 };      // Frequency array for lowercase letters
        int i           = 0;          // Left pointer of sliding window
        int j           = 0;          // Right pointer of sliding window
        int result      = 0;          // Count of substrings
        int distinctCnt = 0;          // Number of distinct characters in current window

        while (j < n) {
            // If the character is new to the window
            if (mp[s[j] - 'a'] == 0) {
                distinctCnt++;
            }
            mp[s[j] - 'a']++; // Add current character to the window

            // Shrink the window until we have at most k distinct characters
            while (distinctCnt > k) {
                mp[s[i] - 'a']--;  // Remove from left
                if (mp[s[i] - 'a'] == 0) {
                    distinctCnt--; // A distinct character is completely removed
                }
                i++;
            }

            result += j - i + 1; // All substrings ending at j with at most k distinct
            j++;
        }
        return result;
    }
    int countSubstr(string& s, int k) {
        // Count substrings with exactly k distinct characters
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};
