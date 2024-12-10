class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n=intervals.size();
        if (n == 0) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prevEnd = intervals[0][1];
        
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < prevEnd) {
                count++;
                prevEnd =min(prevEnd, intervals [i][1]);
            } else {
                prevEnd = intervals[i][1];
            }
        }
        
        return count;
    }
};
