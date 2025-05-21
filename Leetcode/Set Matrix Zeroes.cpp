//Company Tags  : Microsoft, Amazon
//Leetcode Link : https://leetcode.com/problems/set-matrix-zeroes/

//Approch-1 (Using extra space of m*n)
//T.C : O(m*n*(m+n))
//S.C : O(m*n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        temp[i][k] = 0;  // zero out the entire row
                    }
                    for (int k = 0; k < m; k++) {
                        temp[k][j] = 0;  // zero out the entire column
                    }
                }
            }
        }

        matrix = temp;
    }
};


//Approch-2 (Using m+n extra space)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();        // number of rows
        int n = matrix[0].size();     // number of columns

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true; //mark it for zero
                    col[j] = true; //mark it for zero
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//Approach-3 (In place constant space)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        // Check first row and col separately
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) 
                firstColZero = true;
        }

        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) 
                firstRowZero = true;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }


        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowZero) {
            for(int j = 0; j < n; j++) 
                matrix[0][j] = 0;
        }
        if(firstColZero) {
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;
        }
    }
};
