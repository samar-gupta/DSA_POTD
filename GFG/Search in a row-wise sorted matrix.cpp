//Approach-1 : 
//For n rows and m columns, binary search on each row takes O(log m).
//T.C : Overall complexity: O(n * log m).
//S.C : O(1)
class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        // Iterate through each row in the matrix
        for (vector<int> &row : mat) {
            // Perform binary search using lower_bound in the current row
            auto lb = lower_bound(row.begin(), row.end(), x) - row.begin();
            // Check if the found element is equal to x
            if (lb != row.size() && row[lb] == x) 
                return true; // Return true if found
        }
        // If the target is not found in any row, return false
        return false;
    }
};
