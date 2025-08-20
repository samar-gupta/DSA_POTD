//Leetcode Link : https://leetcode.com/problems/maximal-square/description/

//Approach-1 : (simple Recursion Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int solve(int i, int j , int n , int m,  vector<vector<char>>& matrix ,  vector<vector<int>>&t){
     if( i >= n || j >= m || matrix[i][j] == '0' ) return 0;
     
     if(t[i][j] != -1) return t[i][j];
     int right = solve(i, j+1, n, m, matrix, t);
     int below = solve(i+1, j, n, m, matrix, t);
     int diag =  solve(i+1, j+1, n, m, matrix, t);

     return t[i][j] =  1 + min({right, below, diag});
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>>t(n+1, vector<int>(m+1 , -1));
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') { 
                   int temp = solve(i, j, n, m, matrix, t);
                   ans = max(ans, temp*temp);
                }  
            }  
        }
        
        return ans;
    }
};


//Approach-2 (simple Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // DP table with padding
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(matrix[i-1][j-1] == '1') {
                    t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
                    ans = max(ans, t[i][j]);
                }
            }
        }
        return ans * ans; // return area
    }
};
