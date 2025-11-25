//Leetcode Link : https://leetcode.com/problems/smallest-integer-divisible-by-k/

//Approach - Observation about Modulo(%) values
//T.C : O(k)
//S.C : O(1)
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K == 1)
            return 1;
        if(K%2 == 0 || K%5 == 0)
            return -1;
        
        int remain = 0;
        for(int i = 1; i<=K; i++) {
            remain = (remain*10 + 1)%K; //remainder will never exceed k-1, hence avoiding integer overflow

            if(remain == 0)
                return i;
        }

        return -1;
    }
};
