// Approach 1: For each element in a, iterate through b and count elements ≤ a[i] using a nested loop.
// Time Complexity: O(n * m) where n = a.size() and m = b.size().
// Space Complexity: O(n) for the result array.
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();                 // number of elements in a
        int m = b.size();                 // number of elements in b

        vector<int> result(n);            // answer array

        // For each element in a[], count how many in b[] are ≤ a[i]
        for (int i = 0; i < n; i++) {
            int count = 0;                // reset count for a[i]
            for (int j = 0; j < m; j++) {
                if (b[j] <= a[i]) {       // if b[j] is ≤ current a[i]
                    count++;              // increment count
                }
            }
            result[i] = count;            // store the count in result
        }
        return result;
    }
};


// Approach 2: Sort b, then for each element in a, perform binary search to find the first index where b[idx] > a[i]; that index equals the count of ≤ a[i].
// Time Complexity: O(m log m + n log m) where m = b.size() for sorting and n = a.size() for binary searches.
// Space Complexity: O(1) extra (excluding output vector).
class Solution {
public:
    // Custom binary search: returns the first index > x in sorted b[], which is the count of elements ≤ x
    int binarySearch(vector<int>& b, int x) {
        int low = 0, high = b.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // avoid overflow
            if (b[mid] <= x) {
                low = mid + 1;                // move right to find first > x
            }else {
                high = mid - 1;               // move left
            }
        }
        return low;                          // low is the count of elements ≤ x
    }

    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();                   // number of elements in a
        int m = b.size();                   // number of elements in b

        vector<int> result(n);              // answer array

        sort(b.begin(), b.end());           // sort b for binary search

        // For each element in a[], count how many in b[] are ≤ a[i] via binarySearch
        for (int i = 0; i < n; i++) {
            result[i] = binarySearch(b, a[i]);
        }
        return result;
    }
};


// Approach 3: Sort array b, then for each element in a use std::upper_bound to get the first position > a[i], whose index equals the count of elements ≤ a[i].
// Time Complexity: O(m log m + n log m) where m = b.size() for sorting and n = a.size() for n binary searches.
// Space Complexity: O(1) extra space (ignoring the output vector).
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();                 // number of elements in a
        int m = b.size();                 // number of elements in b

        vector<int> result(n);            // answer array

        sort(b.begin(), b.end());         // sort b to enable binary search

        // For each a[i], upper_bound returns iterator to first element > a[i]
        // distance from b.begin() gives count of elements ≤ a[i]
        for (int i = 0; i < n; i++) {
            result[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        }

        return result;
    }
};


// Approach 4: Use a fixed-size frequency array for b (range 0–100000), build its prefix sums, then for each element in a look up the count in O(1).
// Time Complexity: O(m + U + n) where m = b.size(), U = 100001 (constant), and n = a.size().
// Space Complexity: O(U) for the frequency/prefix array.
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size();                         // number of elements in a
        int m = b.size();                         // number of elements in b

        vector<int> result(n);                    // answer array
        vector<int> freq(100001, 0);              // freq[i] = count of i in b

        // fill frequency array
        for (int i = 0; i < m; i++) {
            freq[b[i]]++;                         // increment count of value b[i]
        }

        // compute prefix sums so freq[i] = count of elements ≤ i
        for (int i = 1; i < 100001; i++) {
            freq[i] += freq[i - 1];
        }

        // for each element in a, lookup count in freq[]
        for (int i = 0; i < n; i++) {
            result[i] = freq[a[i]];
        }

        return result;
    }
};


// Approach 5: Build a frequency array of b up to the maximum of a, compute its prefix sums, then for each element in a, look up the count in O(1).
// Time Complexity: O(n + m + maxA) where n = a.size(), m = b.size(), and maxA = max(a).
// Space Complexity: O(maxA) for the frequency/prefix array.
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int         n = a.size();                    // number of elements in a
        int         m = b.size();                    // number of elements in b
        vector<int> result(n);                       // answer array

        int maxA = *max_element(a.begin(), a.end()); // find the maximum value in a

        vector<int> freq(maxA + 1, 0);               // freq[i] = count of i in b (if i <= maxA)

        // Build frequency array for b[]
        for (int i = 0; i < m; i++) {
            if (b[i] <= maxA) {
                freq[b[i]]++;                     // increment count of b[i]
            }
        }

        // Convert freq[] into prefix sum array so freq[i] = count of elements ≤ i
        for (int i = 1; i <= maxA; i++) {
            freq[i] += freq[i - 1];
        }

        // For each element in a, the answer is freq[a[i]] (number of b elements ≤ a[i])
        for (int i = 0; i < n; i++) {
            result[i] = freq[a[i]];
        }

        return result;
    }
};
