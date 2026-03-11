//Leetcode Link : https://leetcode.com/problems/complement-of-base-10-integer

//Approach-1
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        
        int result = 0;
        int counter = 0;
        while(n) {
            int r = n%2;
            result += (pow(2,counter)*!r);
            counter++;
            n = n>>1;
        }
        return result;
    }
};


//Approach-2
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int mask = 1;

        while (mask < n) {
            mask = (mask << 1) | 1;  // builds 111...1
        }
        
        return n ^ mask;
    }
};


//Approach-3
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        int bits = floor(log2(n)) + 1;  // number of bits
        int mask = (1 << bits) - 1;     // 2^bits - 1 = 111...1

        return n ^ mask;
    }
};
