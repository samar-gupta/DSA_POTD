/*
Let:
cells = n * m

Total ordered placements:
total = cells * (cells - 1)

Now count attacking placements.
A 2 × 3 rectangle can be placed:
(n - 1) * (m - 2) times

Inside each such rectangle there are 2 attacking knight pairs.

Similarly, a 3 × 2 rectangle can be placed:
(n - 2) * (m - 1) times

Again, each contributes 2 attacking pairs.

So total attacking unordered pairs:
2 * ((n - 1) * (m - 2) + (n - 2) * (m - 1))

Since black and white knights are different, each pair can be arranged in 2 ways:
attacking = 4 * ((n - 1) * (m - 2) + (n - 2) * (m - 1))

Finally:
answer = total - attacking

For small dimensions, terms like (n - 2) or (m - 2) can become negative. 
I simply count a rectangle type only when it actually fits on the board.
*/
class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        long long cells = 1LL * n * m;

        long long total = cells * (cells - 1);

        long long attacking = 0;

        if (n >= 2 && m >= 3) {
            attacking += 4LL * (n - 1) * (m - 2);
        }

        if (n >= 3 && m >= 2) {
            attacking += 4LL * (n - 2) * (m - 1);
        }

        return (int)(total - attacking);
    }
};
