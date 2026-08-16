//Approach :
/*
I scan the array once.
  I keep track of:
    negativeCount — how many negative numbers are present.
    zeroCount — whether zero is present.
    product — product of all non-zero elements.
    smallestAbsNegative — the negative number whose absolute value is smallest.
    smallestPositive — the smallest positive number.

If there are no negative numbers:
  If there is a zero, I return 0.
  Otherwise, I return the smallest positive number.

If negative numbers exist:
  If the number of negatives is odd, I use all non-zero elements.
  If the number of negatives is even, I remove the negative number with the smallest absolute value.
  Zeros are ignored because a negative product is always smaller than 0.


For example, with [4, -2, 5], there are two negative numbers? No, there is only one negative number, -2, so I use every non-zero element:
4 × -2 × 5 = -40
For [-2, -3, 4], there are two negative numbers. I remove -2 because its absolute value is smaller:
-3 × 4 = -12
That is smaller than any positive or zero product.
*/
class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int negativeCount = 0;
        int smallestPositive = INT_MAX;
        int smallestAbsNegative = INT_MAX;
        long long product = 1;
        bool hasZero = false;

        for (int x : arr) {
            if (x == 0) {
                hasZero = true;
                continue;
            }

            product *= x;

            if (x < 0) {
                negativeCount++;
                smallestAbsNegative = min(
                    smallestAbsNegative, -x
                );
            } else {
                smallestPositive = min(
                    smallestPositive, x
                );
            }
        }

        if (negativeCount == 0) {
            if (hasZero) {
                return 0;
            }

            return smallestPositive;
        }

        if (negativeCount % 2 == 0) {
            product /= -smallestAbsNegative;
        }

        return (int)product;
    }
};
