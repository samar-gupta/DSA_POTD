class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        int left = 63; // assuming 64-bit number
        
        while (left >= 0 && ((N >> left) & 1) == 0) {
            left--;
        }
        
        int right = 0; // least significant bit
        
        while (left > right) {
            int leftBit = (N >> left) & 1;   // extract left bit
            int rightBit = (N >> right) & 1; // extract right bit
            
            if (leftBit != rightBit) return 0;
            
            left--;
            right++;
        }
        
        return 1; // all bits matched
    }
};
