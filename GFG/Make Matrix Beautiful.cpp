class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int mx=INT_MIN;
        int total=0;
        
        for(int i=0;i<n;i++){
            int row_sum=0, col_sum=0;
            for(int j=0;j<n;j++){
                row_sum += mat[i][j];
                col_sum += mat[j][i];
                total   += mat[i][j];
            }
            mx=max(mx,max(row_sum,col_sum));
        }
        
        return (n*mx-total);
    }
};
