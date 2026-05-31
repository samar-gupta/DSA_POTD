/*
A number can be represented as a sum of consecutive positive integers 
   iff it is not a power of 2

If n is a power of 2, the answer is false.
   Otherwise, the answer is true.

only the number which has odd prime 
   factor can be written as sum of two prime 
*/
class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        if ((n & (n - 1)) == 0)
            return false;

        return true;
    }
};
