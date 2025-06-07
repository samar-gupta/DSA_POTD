// Approach 1: Use brute force nested loops to check every possible subarray and update the maximum length when the sums of a1 and a2 are equal.
// Time Complexity: O(n^2) due to the two nested loops over the array of size n.
// Space Complexity: O(1) since only a constant amount of extra space (sum1, sum2, result) is used.
class Solution {
public:
    int longestCommonSum(vector<int>& a1, vector<int>& a2) {
        int n      = a1.size();
        int result = 0;                // stores the maximum length found so far

        // Check all possible subarrays by choosing start index i
        for (int i = 0; i < n; i++) {
            int sum1 = 0;              // cumulative sum of a1 from i to j
            int sum2 = 0;              // cumulative sum of a2 from i to j

            // Extend the subarray to end index j
            for (int j = i; j < n; j++) {
                // Accumulate sums for current subarray [i..j]
                sum1 += a1[j];
                sum2 += a2[j];

                // If the two sums match, update result with current span length
                if (sum1 == sum2) {
                    result = max(result, j - i + 1);
                }
            }
        }

        return result;
    }
};


// Approach 2: Use running difference and a hash map to track the first occurrence of each difference; when the same diff repeats, update the span length.
// Time Complexity: O(n) — single pass over the arrays with O(1) average map operations.
// Space Complexity: O(n) — for storing differences in the hash map.
class Solution {
public:
    int longestCommonSum(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        unordered_map<int, int> mp;    // maps diff -> first index it was seen
        int sum1 = 0, sum2 = 0, result = 0;

        for (int i = 0; i < n; i++) {
            sum1 += a1[i];
            sum2 += a2[i];
            int diff = sum1 - sum2;

            if (diff == 0) {
                // from 0..i is balanced
                result = max(result, i + 1);
            }else if (mp.count(diff)) {
                // seen this diff before, subarray (mp[diff]+1..i) is balanced
                result = max(result, i - mp[diff]);
            }else {
                // first time seeing this diff
                mp[diff] = i;
            }
        }
        return result;
    }
};
