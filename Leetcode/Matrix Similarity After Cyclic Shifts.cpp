//Leetcode Link : https://leetcode.com/problems/matrix-similarity-after-cyclic-shift

//Approach-1 (Simulation + extra space)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp = mat;
        int m = mat.size();
        int n = mat[0].size();
        k = k%n;
        if(k == 0) { //no shifting
            return true;
        }
      
        for(int i = 0; i<m; i++) {
            if(i%2) { // odd
                rotate(rbegin(mat[i]), rbegin(mat[i]) + k, rend(mat[i]));
            } else {
                rotate(begin(mat[i]), begin(mat[i]) + k, end(mat[i]));
            }
        }

        return temp == mat;
    }
};


//Approach-2 (Without rotation and O(1) space)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = (k%n);

        if(k == 0) { //no shifting
            return true;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int currIdx = j;
                int finalIdx;

                if(i % 2 == 0) { //even : left shift
                    finalIdx = (j + k)%n;
                } else {
                    finalIdx = (j - k + n) % n;
                }

                if(mat[i][currIdx] != mat[i][finalIdx]) {
                    return false;
                }

            }
        }

        return true;
    }
};
