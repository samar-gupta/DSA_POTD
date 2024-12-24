class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(mat[i][j]==x) return true;
            else if(x>mat[i][j]) i++;
            else j--;
        }
        return false;
    }
};
