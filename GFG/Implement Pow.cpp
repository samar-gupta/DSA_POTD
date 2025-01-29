class Solution {
  public:
    double power(double b, int e) {
        // code here
        // Base case: any number raised to the power of 0 is 1
        if (e < 0) {
            return 1 / power(b, -e);
        }
        if (e == 1) {
            return b;
        }
        if (e == 0) {
            return 1;
        }

        double halfPow = power(b, e / 2);
        if (e % 2 == 0) {
            return halfPow * halfPow;
        }
        return b * halfPow * halfPow;
    }
};
