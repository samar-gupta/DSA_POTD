//Approach:
class Solution {
  public:
    int countLessEqual(vector<vector<int>> &mat, int mid) {
        int count = 0;
        int n = mat.size();
        int row = n - 1; // Start from bottom-left
        int col = 0;

        while (row >= 0 && col < n) {
            if (mat[row][col] <= mid) {
                // Since columns are sorted, if mat[row][col] <= mid,
                // then all elements above it in this column are also <= mid.
                count += (row + 1);
                col++;
            } else {
                // If the element is too large, move up to a smaller value
                row--;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Count how many numbers are <= mid
            int count = countLessEqual(mat, mid);

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};



//old
//Approach-1:
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size();

        vector<int> result;               

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.push_back(matrix[i][j]);
            }
        }
        sort(result.begin(), result.end());
        return result[k - 1];  
    }
};


//Approach-2:
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size();

        priority_queue<int> pq; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (pq.size() < k) {
                    pq.push(val);
                } else if (val < pq.top()) {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
        return pq.top();
    }
};


//Approach-3:
class Solution {
  public:
    int count(int mid, vector<vector<int> >& matrix) {
        int n = matrix.size();

        int i = 0;
        int j = n - 1;

        int countSum = 0;

        while (i < n && j >= 0) {
            if (matrix[i][j] <= mid) {
                countSum += (j + 1);
                i++;
            } else {
                j--;
            }
        }
        return countSum;
    }
    
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size();

        int l = matrix[0][0];
        int h = matrix[n - 1][n - 1];

        while (l < h) {
            int mid = l + (h - l) / 2;
            if (count(mid, matrix) >= k) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
