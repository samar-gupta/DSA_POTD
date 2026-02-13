class Solution {
  public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int getCount(int n, int d) {
        // code here
        int low = 1, high = n;
        int min_val = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (mid - getSum(mid) >= d) {
                min_val = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (min_val == -1) return 0;

        return n - min_val + 1;
    }
};
