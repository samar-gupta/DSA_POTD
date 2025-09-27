//Approach-1 : 
/*
Intuition :
  1. Greedy Choice (Left to Right)
       • Suppose we’re at index i.
       • If the current bit (after considering past flips) is 0, then the only way to make it 1 is to flip starting from i.
       • Why? Because future flips starting beyond i cannot affect arr[i].
       • So we must decide flips greedily from left to right.
  2. Lazy Flip Tracking
       • Actually flipping subarrays is costly (O(n·k)).
       • Instead, track whether the current position is under the effect of an odd/even number of flips.
       • Use:
           • A flipped flag = current parity of flips.
           • A queue or auxiliary array to know when a flip’s effect ends.
  3. When to Flip
       • At index i, effective value = arr[i] ^ flipped.
       • If it’s 0, we must flip starting at i.
       • If i + k > n, not enough room → return -1.

Approach : 
   Step-by-Step
       1. Iterate from i = 0 to n-1.
       2. Expire old flips when we cross their end (i - k).
       3. If (arr[i] ^ flipped) == 0, we must flip:
            • Increment flip counter.
            • Mark flip ending at i + k.
            • Toggle flipped.
       4. Continue until end.
       5. Return total flips.
*/
//T.C : O(n) → each index processed once.
//S.C : With queue: O(k) (storing flip-end indices). With optimized trick: O(1) extra
class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int flips = 0;       // total flips
        int flipped = 0;     // current parity of flips
        vector<int> isFlipped(n, 0); // marks where a flip starts

        for (int i = 0; i < n; i++) {
            // remove effect of flips that ended
            if (i >= k) {
                flipped ^= isFlipped[i - k];
            }

            // if current bit is effectively 0 → must flip
            if ((arr[i] ^ flipped) == 0) {
                if (i + k > n) return -1;  // not enough space
                flips++;
                flipped ^= 1;              // start new flip
                isFlipped[i] = 1;          // mark flip started here
            }
        }
        return flips;
    }
};
