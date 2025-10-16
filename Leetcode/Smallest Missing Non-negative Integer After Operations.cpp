//Leetcode Link : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations

//NOTE : Adding value to any number doesn’t change its remainder modulo value, so what really matters is the frequency of each remainder when the numbers are divided by value.
//Approach - Observation about Modulo(%) values
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;

        for(int &num : nums) {
            int r = ((num % value) + value) % value;

            mp[r]++;
        }

        int MEX = 0;

        while(mp[(MEX % value)] > 0) {
            mp[(MEX % value)]--;

            MEX++;
        }

        return MEX;
    }
};
