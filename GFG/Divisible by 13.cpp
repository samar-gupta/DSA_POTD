//Approach-1 : 
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int remainder = 0;  // Initialize remainder to 0
        
        // Process each digit from left to right
        for (char digit : s) {
            // Convert character to integer and add to shifted remainder
            remainder = (remainder * 10 + (digit - '0')) % 13;
        }
        
        // If remainder is 0, number is divisible by 13
        return remainder == 0;
    }
};
