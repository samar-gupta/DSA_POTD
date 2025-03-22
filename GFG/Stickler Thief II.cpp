//This is a variation of the House Robber problem where the houses are arranged in a circle. The main difference from the linear version is that in a circular arrangement, the first and last house are adjacent, so they cannot be robbed together.
/* Approach : 
     1. If we ignore the first house, the problem reduces to finding the maximum value from houses 1 to n-1.
     2. If we ignore the last house, the problem reduces to finding the maximum value from houses 0 to n-2.
     3. The final result is the maximum of these two cases.
*/
//T.C: O(N)   (since we traverse the array twice)
//S.C : O(1)  (using only a few variables instead of extra arrays)
class Solution {
  public:
    int rob(vector<int>& arr, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int take = arr[i] + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        // Compute the max value excluding the last house
        int max1 = rob(arr, 0, n - 2);
        // Compute the max value excluding the first house
        int max2 = rob(arr, 1, n - 1);

        return max(max1, max2);
    }
};
