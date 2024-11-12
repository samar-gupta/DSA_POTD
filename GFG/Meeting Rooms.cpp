class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for (int i = 1 ; i < n ; i++) {
            if (arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        
        return true;
    }
};
