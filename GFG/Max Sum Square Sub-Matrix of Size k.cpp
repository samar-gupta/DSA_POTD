//Approach-1 :
/*
First, I create a 2D prefix sum matrix.
For every cell (i, j), the prefix matrix stores the sum of all elements from (0, 0) to (i, j).

The formula is:
  prefix[i][j] =
  mat[i][j]
  + top
  + left
  - top-left

where:
  top is the prefix value above the current cell.
  left is the prefix value to the left.
  top-left is subtracted because it gets counted twice.

After building the prefix matrix, I iterate over every possible bottom-right corner of a k × k square.
Using the prefix matrix, I calculate the square sum in constant time.

For a square with:
  Top-left = (r1, c1)
  Bottom-right = (r2, c2)

the sum becomes:
  sum =
  prefix[r2][c2]
  - prefix[r1-1][c2]
  - prefix[r2][c1-1]
  + prefix[r1-1][c1-1]

I compare every square sum with the current maximum and update the answer whenever I find a larger one.
Finally, I return the maximum sum.
*/
class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n = mat.size();

        vector<vector<int>> prefix(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                prefix[i][j] = mat[i][j];

                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];

                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];

                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;

        for (int i = k - 1; i < n; i++) {
            for (int j = k - 1; j < n; j++) {

                int r = i - k + 1;
                int c = j - k + 1;

                int sum = prefix[i][j];

                if (r > 0)
                    sum -= prefix[r - 1][j];

                if (c > 0)
                    sum -= prefix[i][c - 1];

                if (r > 0 && c > 0)
                    sum += prefix[r - 1][c - 1];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
