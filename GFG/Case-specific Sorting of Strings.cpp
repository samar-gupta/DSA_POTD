// Approach 1: Separate lowercase and uppercase letters, sort each group, then rebuild the string by choosing from the appropriate sorted group based on the original character’s case.
// Time Complexity: O(n + k log k) where n = length of s, k is roughly n/2 for each group; overall dominated by sorting at O(n log n).
// Space Complexity: O(n) extra space for the two buckets storing characters.
class Solution {
public:
    string caseSort(string& s) {
        int n = s.length();

        vector<char> lower;  // to hold all lowercase letters
        vector<char> upper;  // to hold all uppercase letters

        // 1) Partition into lowercase and uppercase buckets
        for (char ch : s) {
            if (islower(ch)) {
                lower.push_back(ch);
            } else {
                upper.push_back(ch);
            }
        }

        // 2) Sort both buckets independently
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // 3) Reconstruct result by consuming from sorted buckets
        string result = s;  // initialize result with original size
        int    l      = 0;  // index for lowercase bucket
        int    u      = 0;  // index for uppercase bucket

        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                result[i] = lower[l++];  // place next sorted lowercase
            } else {
                result[i] = upper[u++];  // place next sorted uppercase
            }
        }

        return result;
    }
};


// Approach 2: Count lowercase and uppercase letters using fixed-size frequency arrays, then rebuild the string by picking the next available character from the corresponding frequency array in order.
// Time Complexity: O(n + 26) ⇒ O(n), where n = length of s.
// Space Complexity: O(1) extra space for two fixed-size arrays of length 26.
class Solution {
public:
    string caseSort(string& s) {
        int n = s.size();

        int lower[26] = { 0 };
        int upper[26] = { 0 };

        // 1) Count frequencies
        for (char ch : s) {
            if (islower(ch)) {
                lower[ch - 'a']++;
            } else {
                upper[ch - 'A']++;
            }
        }

        // 2) Reconstruct result by consuming counts
        string result = s;
        int    l      = 0; // index for lowercase freq array
        int    u      = 0; // index for uppercase freq array

        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                while (lower[l] == 0) {
                    l++;
                }
                result[i] = 'a' + l;
                lower[l]--;
            } else {
                while (upper[u] == 0) {
                    u++;
                }
                result[i] = 'A' + u;
                upper[u]--;
            }
        }

        return result;
    }
};
