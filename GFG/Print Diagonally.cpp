class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n=mat.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int row=0,col=i;
            while(col>=0){
                ans.push_back(mat[row][col]);
                row++,col--;
            }
        }
        for(int k=1;k<n;k++){
            int row=k,col=n-1;
            while(row<n){
                ans.push_back(mat[row][col]);
                row++,col--;
            }
        }
        return ans;
    }
};
