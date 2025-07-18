//Approach-1 : 
//T.C : O(1)
//S.C : O(1)
class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
        // Small n can be answered immediately
        if (n <= 2) return n;      // {1} → 1, {2,1} → 2
        if (n == 3)  return 6;     // LCM(1,2,3) = 6

        // Case 1: n is odd → perfect trio n, n‑1, n‑2
        if (n & 1) {               // bit‑check for odd
            return n * (n - 1) * (n - 2);
        }

        // Case 2: n is even
        if (n % 3 != 0) {
            // Even but NOT divisible by 3 → use n, n‑1, n‑3
            return n * (n - 1) * (n - 3);
        }
        // Case 3: n is a multiple of 6 → step left to (n‑1, n‑2, n‑3)
        return (n - 1) * (n - 2) * (n - 3);
    }
};
