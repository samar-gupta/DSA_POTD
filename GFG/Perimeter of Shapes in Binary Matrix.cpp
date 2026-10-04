//Approach :
/*
1. Go through every cell in the matrix.
2. When the current cell is 1, add 4 to the perimeter.
3. Check the cell to the right:
     If it is also 1, subtract 2.
4. Check the cell below:
     If it is also 1, subtract 2.
5. Only check right and down so the same pair is never counted twice.
6. Return the final perimeter.
*/
class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int peri = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    peri += 4;
                    if (j + 1 < m && mat[i][j + 1] == 1) peri -= 2;
                    if (i + 1 < n && mat[i + 1][j] == 1) peri -= 2;
                }
            }
        }
        return peri;
    }
};
