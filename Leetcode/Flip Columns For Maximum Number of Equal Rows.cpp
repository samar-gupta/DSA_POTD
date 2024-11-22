//Leetcode Link : https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

//Approach-1 (Brute Force)
//T.C : O(row^2 * col)
//S.C : O(col)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int maxRows = 0;

        for (auto& currRow : matrix) {

            vector<int> inverted(n);
            int count = 0;

            
            for (int col = 0; col < n; col++) {
                inverted[col] = currRow[col] == 0 ? 1 : 0;
            }

            for (auto& row : matrix) {

                if (row == currRow || row == inverted) {
                    count++;
                }
            }

            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};


//Approach-2 (Using hashmap to store patterns)
//T.C : O(row * col)
//S.C : O(row*col)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp; //O(m*n)

        for(auto &row : matrix) { //O(m)
            string rowKaNature = "";

            int firstVal = row[0];
            for(int col = 0; col < n; col++) { //O(n)
                rowKaNature += (row[col] == firstVal) ? "S" : "B";
            }

            mp[rowKaNature]++;
        }

        int maxRows = 0;
        for(auto &it : mp) {
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};
