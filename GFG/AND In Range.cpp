//Approach-1 : 
/*
  The bitwise AND
  of all numbers in the range [l,r] will keep only the
  common prefix bits of l and r.
  As soon as a bit differs between l and r, 
  everything below that bit becomes zero in the result.
  So the answer is essentially the common prefix of l and r in binary.
*/
class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int count = 0;
        // Keep shifting until l == r
        while (l < r) 
        {
            l >>= 1;
            r >>= 1;
            count++;
        }
        // Shift back to restore common prefix
        return (l << count);
    }
};
