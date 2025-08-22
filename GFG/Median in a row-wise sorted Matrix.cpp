//Approach-1 : 
//T.C : O(logk.logn.n), k is the range (max - min)
//S.C : O(1)
class Solution {
  public:
    int countSmallerOrEqual(vector<int>& row, int mid) {

        int l = 0, r = row.size() - 1;

        
        while (l <= r) {
            int m = (l + r) / 2;
            
            if (row[m] <= mid) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
    
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();

        int m = mat[0].size();


        int low = INT_MAX, high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(low, mat[i][0]);      
            high = max(high, mat[i][m - 1]); 
        }

        int req = (n * m + 1) / 2; 

        while (low < high) {
            int mid = low + (high - low) / 2;
            int place = 0;

            for (int i = 0; i < n; i++) {
                place += countSmallerOrEqual(mat[i], mid);
            }

            if (place < req)  low = mid + 1;
            else  high = mid;
        }

        return low;
    }
};
