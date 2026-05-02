class Solution {
  public:
    int findPosition(int n) {
        // code here
        if (n == 0) return -1;
        
        if ((n & (n - 1)) != 0) return -1;
        
        int position = 1;
        
        while (n > 0) {
            if (n & 1) return position;
            
            n = n >> 1;
            
            position++;
        }
        
        return -1;
    }
};
