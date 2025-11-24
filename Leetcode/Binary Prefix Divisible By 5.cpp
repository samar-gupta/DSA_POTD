//Leetcode Link : https://leetcode.com/problems/binary-prefix-divisible-by-5

//Approach (Using bit concept and modular arithmetic)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result(n);

        int remain = 0;
        
        for(int i = 0; i < n; i++) {
            remain = (remain*2 + nums[i]) % 5;

            result[i] = (remain == 0);
        }

        return result;
    }
};
