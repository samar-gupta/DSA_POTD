//Approach-1 :
/*
I scan the string from left to right.
When I find a router at position i, I do three checks:

First, if it is the first router I have seen, I store its position. 
  I later use it to check whether the left side of the hostel is covered.

Second, I compare it with the previous router. If the distance between two routers is too large, 
  then their coverage intervals do not touch, and some rooms in the middle stay uncovered.
  Two routers at positions a and b cover everything between them only if b - a <= 2 * x + 1.

Third, after the scan ends, I check the last router. 
  If it is too far from the right edge, 
  then the last rooms are not covered.

I also handle the case where there is no router at all. 
In that case, the answer is clearly false.

This works in one pass and uses only a few variables.
*/
class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.size();

        int first = -1, prev = -1, last = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first == -1) first = i;

                if (prev != -1 && i - prev > 2 * x + 1) {
                    return false;
                }

                prev = i;

                last = i;
            }
        }

        if (first == -1) return false;

        if (first > x) return false;

        if (n - 1 - last > x) return false;

        return true;
    }
};
