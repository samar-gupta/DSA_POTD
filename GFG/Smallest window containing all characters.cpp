//Approach-1 : 
class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        // If pattern is longer than string, no valid window exists
        if (p.length() > s.length()) return "";

        // Map to store frequency of each character in pattern
        unordered_map<char, int> required;
        for (char ch : p) {
            required[ch]++;
        }

        int start = 0;                  // Left boundary of sliding window
        int minLen = INT_MAX;           // Length of smallest valid window found
        int minStart = 0;               // Starting index of smallest window
        int count = p.length();         // Total characters we need to match

        // Expand the window by moving 'end'
        for (int end = 0; end < s.length(); end++) {
            char ch = s[end];

            // If this character is still needed, reduce count
            if (required[ch] > 0) {
                count--;
            }
            // Decrease frequency in map (can go negative if extra occurrences)
            required[ch]--;

            // When all characters are matched (count == 0)
            while (count == 0) {
                // Update minimum window if current one is smaller
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                // Try to shrink window from the left
                char startChar = s[start];
                required[startChar]++;

                // If removing startChar breaks the requirement, increase count
                if (required[startChar] > 0) {
                    count++;
                }
                start++; // Move left boundary forward
            }
        }

        // If no valid window found, return empty string
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};


//Approach-1 : (Sliding Window)
//T.C : O(N)
//S.C : O(26) ~ O(1)
class Solution {
  public:
    string smallestWindow(string &s, string &t) {
        // code here
        int n = s.size();
        vector<int> f(26, 0); 
        int minLen = INT_MAX;
        int resStart = 0;

        for (char ch : t) f[ch - 'a']++;

        int count = t.size();
        int l = 0;

        for (int r = 0; r < n; r++) {
            char ch = s[r];
            if (f[ch - 'a'] > 0) count--;
            f[ch - 'a']--;

            while (count == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    resStart = l;
                }

                char ch2 = s[l];
                f[ch2 - 'a']++;
                if (f[ch2 - 'a'] > 0) count++;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(resStart, minLen);
    }
};
