class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int n=s.size();
        int maxSum = -1;
        int currSum = 0;
        
        for(int i = 0; i < n; i++) {
            int val = (s[i] == '0') ? 1 : -1;
            currSum += val;
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};
