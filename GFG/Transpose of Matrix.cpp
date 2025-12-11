//Approach: 
//inner loop: j = i
//When i == j, it swaps the same element with itself, which does nothing. 
// But it is still safe and correct. 
// Covers all upper-triangle including diagonal.
//inner loop: j = i + 1          
//Skips diagonal (j = i+1 means j > i).
// Only swaps strictly upper triangle, no redundant swaps.
// More efficient (fewer operations), but same final result.
class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i = 0;i<n;i++)
            for(int j = i+1;j<n;j++)                     
              swap(mat[i][j],mat[j][i]);
        return mat;
    }
};
