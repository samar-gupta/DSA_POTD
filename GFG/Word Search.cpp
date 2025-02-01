class Solution {
  public:
    
    bool dfs(int row, int col, int index, vector<vector<char>> &mat, string word, vector<vector<int>> &vis){
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, -1, 0, +1};
        
        if(index == word.size()){
            return true;
        }
        
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == word[index]){
                if(dfs(nrow, ncol, index+1, mat, word, vis) == true){
                    return true;
                }
            }
        }
        vis[row][col] = 0;
         return false;
    }
  
  
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
         int m = mat[0].size();
         vector<vector<int>> vis(n, vector<int>(m, 0));
         for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                 if(mat[i][j] == word[0]){
                     if(dfs(i, j, 1, mat, word, vis) == true){
                         return true;
                     }
                 }
             }
         }
         return false;
    }
};
