// Approach 1: Brute-force — collect all elements into a vector, sort, and return the k-th smallest
// Time Complexity: O(n² log(n²)) = O(n² log n) due to sorting n² elements
// Space Complexity: O(n²) for storing all elements
class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int n = matrix.size();

        vector<int> result;                // store all matrix elements

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.push_back(matrix[i][j]);
            }
        }
        sort(result.begin(), result.end()); // sort ascending
        return result[k - 1];               // return k-th smallest (1-based)
    }
};


// Approach 2: Max‐heap — maintain a max-heap of size k, push/pop to keep k smallest
// Time Complexity: O(n² log k) for pushing n² elements into a heap of size ≤ k
// Space Complexity: O(k) for the heap
class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int n = matrix.size();

        priority_queue<int> pq; // max-heap

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
        return pq.top(); // root is k-th smallest
    }
};


// Approach 3: Binary-search on value range + “count ≤ mid” via two-pointer per row
// Time Complexity: O(n log(max−min)) where each count is O(n)
// Space Complexity: O(1)
class Solution {
public:
    // count how many elements ≤ mid
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
    int kthSmallest(vector<vector<int> >& matrix, int k) {
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
