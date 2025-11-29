//Leetcode Link : https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/

//Approach-1 : 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(begin(nums), end(nums), 0) % k;
    }
};
