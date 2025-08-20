//Approach-1 : (treating matrix as 1D array of length n*m) //leetcode-33
//T.C : O(log(n*m))
//S.C : O(1)
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size();

        int l = 0, r = n * m - 1;


        while (l <= r) {
            int mid = l + (r - l) / 2;

            int mv = mat[mid / m][mid % m];
            int lv = mat[l / m][l % m];
            int rv = mat[r / m][r % m];

            if (mv == x) return true;

            if (lv <= mv) {
                
                if (lv <= x && x < mv) r = mid - 1;
                else l = mid + 1;
                
            } else {
                
                if (mv < x && x <= rv) l = mid + 1;
                else r = mid - 1;
                
            }
        }

        return false;
    }
};
