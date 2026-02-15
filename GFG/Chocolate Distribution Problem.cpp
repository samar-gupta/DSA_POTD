class Solution {
  public:
    int findMinDiff(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        
        if(m == 0 || n == 0) return 0;
        if(m > n) return -1;
        
        //sort 
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        
        // check all windows
        for(int i = 0; i + m - 1< n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};
