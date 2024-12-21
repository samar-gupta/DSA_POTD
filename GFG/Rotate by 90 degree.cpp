//Approach-1 : 
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n=mat.size();
    int m=mat[0].size();

    //transpose
    for(int i=0;i<n;i++){       
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    //reverse
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}


//Approach-2 : 
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& matrix) {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
