class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        int size = arr.size();

        // If only one element is present
        if (size == 1) {
            return arr[0];
        }

        const int mod = 1e9 + 7;

        int neg = 0;          // Count of negative numbers
        int zero = 0;         // Count of zeros
        int negMin = mod;     // Smallest absolute negative number

        long long ans = 1;

        // Traverse array
        for (int &val : arr) {

            // Ignore zeros
            if (val == 0) {
                zero++;
                continue;
            }

            // Handle negative numbers
            if (val < 0) {
                neg++;
                negMin = min(negMin, abs(val));
            }

            // Multiply non-zero elements
            ans = (1LL * ans * val) % mod;
        }

        // Case:
        // All elements are zero
        // OR array has one negative and one zero like [-5,0]
        if ((size == zero) || (size == 2 && neg == 1 && zero == 1)) {
            return 0;
        }

        // If count of negatives is odd
        // remove the negative with smallest absolute value
        if (neg % 2 == 1) {
            ans = abs(ans / negMin) % mod;
        }

        return ans;
    }
};
