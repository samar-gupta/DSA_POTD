//Approach-1 :
class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n=mat.size();
        int m=mat[0].size(); 
        vector<vector<int>>diff(n,vector<int>(m,0)); 
        
        for(auto& q: opr){ 
            int v=q[0], r1=q[1], cl=q[2], r2=q[3], c2=q[4]; 
            diff[r1][cl]+=v; 
            if(c2+1<m) diff[r1][c2+1]-=v; 
            if(r2+1<n) diff[r2+1][cl]-=v;
            if(c2+1<m and r2+1<n) diff[r2+1][c2+1]+=v;
        }
        
        for(int i=0; i<n; i++){ 
            for(int j=1; j<m; j++) { 
                diff[i][j]+=diff[i][j-1];
            }
        } 
        
        for(int i=1; i<n; i++){ 
            for(int j=0; j<m; j++) {
                diff[i][j]+=diff[i-1][j];
            }
        }
        
        for(int i=0; i<mat.size(); i++){ 
            for(int j=0; j<mat[0].size(); j++) {
                mat[i][j]+=diff[i][j];
            }
        }
        
        return mat;
    }
};
