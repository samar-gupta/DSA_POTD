// Approach 1: Store mat2 elements in a hash set and iterate through mat1 to check if x - mat1[i][j] exists in the set
// Time Complexity: O(n^2) for traversing mat1 + O(n^2) for inserting mat2 into set = O(n^2)
// Space Complexity: O(n^2) for storing mat2 elements in the hash set
class Solution {
public:
    // Helper: scan mat2 to see if val exists anywhere
    bool find(const vector<vector<int> >& mat2, int needed) {
        int n = mat2.size();

        for (int i2 = 0; i2 < n; i2++) {
            for (int j2 = 0; j2 < n; j2++) {
                if (mat2[i2][j2] == needed) {
                    return true;
                }
            }
        }
        return false;
    }
    int countPairs(vector<vector<int> >& mat1, vector<vector<int> >& mat2, int x) {
        int n     = mat1.size();
        int count = 0;

        // For each element in mat1:
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                int needed = x - mat1[i1][j1]; // Calculate the required complement to form sum x
                if (find(mat2, needed)) {      // Check if the complement exists in mat2
                    count++;
                }
            }
        }

        return count;
    }
};


// Approach 2: Store mat2 elements in a hash set and iterate through mat1 to check if x - mat1[i][j] exists in the set
// Time Complexity: O(n^2) for traversing mat1 + O(n^2) for inserting mat2 into set = O(n^2)
// Space Complexity: O(n^2) for storing mat2 elements in the hash set
class Solution {
public:
    int countPairs(vector<vector<int> >& mat1, vector<vector<int> >& mat2, int x) {
        int n = mat1.size();
        unordered_set<int> st;

        // Step 1: Insert every mat2[i][j] into the hash set
        for (int i2 = 0; i2 < n; i2++) {
            for (int j2 = 0; j2 < n; j2++) {
                st.insert(mat2[i2][j2]); // Add all values of mat2 into set
            }
        }

        int count = 0;

        // Step 2: For each element in mat1, check if (x - mat1[i][j]) exists in the set
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                int needed = x - mat1[i1][j1]; // Compute needed complement
                if (st.count(needed)) {        // Check if complement exists in mat2
                    count++;
                }
            }
        }

        return count;
    }
};


// Approach 3: Flatten both matrices logically, use two pointers (one from start of mat1, one from end of mat2)
// and find pairs whose sum equals x.
// Time Complexity: O(n^2) - each element is visited once
// Space Complexity: O(1) - no extra space used apart from counters
class Solution {
public:
    int countPairs(vector<vector<int> >& mat1, vector<vector<int> >& mat2, int x) {
        int n = mat1.size();

        int i = 0;              // pointer for mat1 (from start)
        int j = n * n - 1;      // pointer for mat2 (from end)

        int count = 0;

        while (i <= n * n - 1 && j >= 0) {
            int a = mat1[i / n][i % n];  // Convert 1D index to 2D for mat1
            int b = mat2[j / n][j % n];  // Convert 1D index to 2D for mat2

            int sum = a + b;

            if (sum == x) {
                count++;
                i++;
                j--;
            } else if (sum < x) {
                i++; // Need bigger sum
            } else {
                j--; // Need smaller sum
            }
        }

        return count;
    }
};
