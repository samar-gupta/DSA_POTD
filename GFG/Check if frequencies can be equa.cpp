// Approach: Count frequency of each character and analyze if at most one character removal can make all frequencies equal.
// Time Complexity: O(n), where n is the length of the string `s`, due to frequency counting.
// Space Complexity: O(1), since we only use a fixed-size array of 26 characters.
class Solution {
public:
    bool sameFreq(string& s) {
        vector<int> freq(26, 0);  // Count frequency of each character (a-z)

        for (char ch : s) {
            freq[ch - 'a']++;  // Increment corresponding index
        }

        int maxFreqValue   = INT_MIN;    // Track the maximum frequency
        int maxFreqCounter = 0;          // Count how many characters have maxFreqValue
        int minFreqValue   = INT_MAX;    // Track the minimum frequency
        int minFreqCounter = 0;          // Count how many characters have minFreqValue

        for (int f : freq) {
            if (f == 0) {
                continue;  // Skip characters not in the string
            }

            if (f == maxFreqValue) {
                maxFreqCounter++;  // If frequency matches max, increment counter
            }

            if (f == minFreqValue) {
                minFreqCounter++;  // If frequency matches min, increment counter
            }

            if (f > maxFreqValue) {
                maxFreqValue   = f;   // Update max frequency
                maxFreqCounter = 1;   // Reset counter for new max
            }

            if (f < minFreqValue) {
                minFreqValue   = f;   // Update min frequency
                minFreqCounter = 1;   // Reset counter for new min
            }
        }

        // Case 1: All characters already have the same frequency
        if ((maxFreqValue - minFreqValue) == 0) {
            return true;
        }
        // Case 2 (Case A or Case B): Only one character has frequency off by 1, or there’s a single char with freq 1
        else if ((maxFreqValue - minFreqValue) == 1 && (maxFreqCounter == 1 ||
                                                        (minFreqValue == 1 && minFreqCounter == 1))) {
            return true;
        }

        return false;  // Not possible by removing only one character
    }
};
