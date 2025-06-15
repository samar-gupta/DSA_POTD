// Approach: Use binary search on the divisor in the range [1, max(arr)], and for each candidate divisor, check if the sum of ceil(arr[i]/divisor) is ≤ k; adjust search bounds based on validity.
// Time Complexity: O(n log m) where n = arr.size() and m = max(arr) due to binary search over [1, m] and O(n) check each time.
// Space Complexity: O(1) auxiliary space besides input.
class Solution {
public:

    bool valid(vector<int>& arr, int mid, int k) {
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += ceil((double)arr[i] / mid); // add the ceiling of arr[i]/mid
            if (sum > k) {
                return false;                  // early exit if sum already exceeds k
            }
        }

        return sum <= k;  // sum ≤ k
    }

    int smallestDivisor(vector<int>& arr, int k) {
        int low    = 1;
        int high   = *max_element(arr.begin(), arr.end());
        int result = 0;

        while (low <= high) {
            int mid = (low + high) / 2;  // mid candidate divisor

            if (valid(arr, mid, k)) {
                result = mid;            // mid works, record and try smaller
                high   = mid - 1;        // search left half
            } else {
                low = mid + 1;           // mid too small, search right half
            }
        }
        return result;
    }
};
