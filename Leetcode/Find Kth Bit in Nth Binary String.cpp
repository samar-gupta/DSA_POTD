//Leetcode Link : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string

//Approach - Recursion
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    char findKthBit(int n, int k) {
        
        if(n == 1) {
            return '0';
        }

        int length = (1 << n) - 1; //pow(2, n) - 1

        if(k < ceil(length/2.0)) {
            return findKthBit(n-1, k);
        } else if(k == ceil(length/2.0)) {
            return '1';
        } else {
            char ch = findKthBit(n-1, length-(k-1)); //handled reversed
            return (ch == '0') ? '1' : '0'; //handled flipped bit
        }

    }
};
