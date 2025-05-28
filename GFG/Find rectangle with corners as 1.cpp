//Approach : 
class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                int cnt = 0;
                for(int row=0; row<n; row++){
                    if(mat[row][i] == 1 && mat[row][j] == 1){
                        cnt += 1;
                    }
                    if(cnt>=2){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


// Approach 1: Check every pair of rows. For each pair, check all column pairs to find two columns where both rows have 1s at those columns, indicating four corners of a rectangle.
// Time Complexity: O(m^2 * n^2), where m is the number of rows and n is the number of columns. For each row pair (O(m^2)), we check all column pairs (O(n^2)).
// Space Complexity: O(1), no extra space used except loop variables.
class Solution {
public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int m = mat.size();       // number of rows
        int n = mat[0].size();    // number of columns

        // Try all pairs of rows
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1 + 1; r2 < m; r2++) {
                // Check for column pairs where both rows have 1
                for (int c1 = 0; c1 < n; c1++) {
                    for (int c2 = c1 + 1; c2 < n; c2++) {
                        // If both rows have 1s at both columns, rectangle is found
                        if (mat[r1][c1] == 1 && mat[r1][c2] == 1 &&
                            mat[r2][c1] == 1 && mat[r2][c2] == 1) {
                            return true;  // Rectangle with 1s found
                        }
                    }
                }
            }
        }

        return false;  // No rectangle found
    }
};



// Approach 2: For each row, collect indices of columns having 1. For each pair of such columns, create a unique key (col1_col2).
// If this key already exists in the set, it means some previous row also had 1s in these two columns => forms a rectangle.
// Time Complexity: O(m * n^2), where m = number of rows and n = number of columns. Each row can have up to n columns with 1s → O(n^2) pairs.
// Space Complexity: O(n^2), for storing all column index pairs in the unordered_set.
class Solution {
public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int r = mat.size();         // number of rows
        int c = mat[0].size();      // number of columns

        unordered_set<string> st;   // to store seen column pairs

        for (int i = 0; i < r; i++) {
            vector<int> cols;       // store column indices where row i has 1

            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) {
                    cols.push_back(j);
                }
            }

            // check all pairs of 1s in current row
            for (int x = 0; x < cols.size(); x++) {
                for (int y = x + 1; y < cols.size(); y++) {
                    string valid_pair = to_string(cols[x]) + "_" + to_string(cols[y]);

                    // if this pair already exists in some previous row → rectangle found
                    if (st.count(valid_pair)) {
                        return true;
                    }

                    // insert this pair for the current row
                    st.insert(valid_pair);
                }
            }
        }

        return false;  // no rectangle with 1s found
    }
};
