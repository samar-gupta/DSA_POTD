//Leetcode Link : https://leetcode.com/problems/remove-covered-intervals

//Approach (Iterate and find)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {
            int shift = nums[i]%n; //reducing the large shifts within 0..n-1 range

            int newIdx = (i + shift) % n;

            if(newIdx < 0) {
                newIdx += n;
            }

            result[i] = nums[newIdx];
        }

        return result;

    }
};
