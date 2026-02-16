//Leetcode Link : https://leetcode.com/problems/reverse-bits

//Approach (Solving bit by bit)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int reverseBits(int n) {
        if (n == 0) return 0;
    
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            

            result = (result | (n & 1));
            
            n >>= 1;
        }

        return result;
    }
};
