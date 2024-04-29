//Compnay Tags  - Amazon
//Leetcode Link - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        
        for(int &num : nums) {
            totalXor ^= num;
        }
        
        
        int diff = (totalXor ^ k);
        
        return __builtin_popcount(diff);
        
    }
};
