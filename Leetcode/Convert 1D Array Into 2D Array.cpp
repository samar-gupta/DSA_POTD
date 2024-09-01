//Leetcode Link : https://leetcode.com/problems/convert-1d-array-into-2d-array

//Approach-1 (Using simply simulation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

        int idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
            }
        }

        return result;
    }
};


//Approach-2 (Using simply math observation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

        for(int i = 0; i < l; i++) {
            result[i/n][i%n] = original[i];
        }

        return result;
    }
};
