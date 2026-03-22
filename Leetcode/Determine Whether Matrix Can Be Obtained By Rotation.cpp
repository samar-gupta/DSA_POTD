//Leetcode Link : https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

//Approach (Rotate and check till 4 rotations)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int n;

    void rotate(vector<vector<int>>& mat) {
        //Transpose

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        //Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        for(int c = 1; c <= 4; c++) {
            
            bool equal = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal)
                    break;
            }

            if(equal)
                return true;
                
            rotate(mat);
        }

        return false;
    }
};
