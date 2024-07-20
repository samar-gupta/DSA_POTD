//Company Tags  : Facebook, Uber, Google, Microsoft
//Leetcode Link : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

//Approach (Using simple Greedy)
//T.C : O(m+n)
//S.C : O(m*n) //You can exclude this because it is what is expected to return from the function
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> vec(m, vector<int>(n));
        
        int i = 0, j = 0;
        while(i < m && j < n) {
            vec[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= vec[i][j];
            colSum[j] -= vec[i][j];

            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
            
        }
        return vec;
    }
};
