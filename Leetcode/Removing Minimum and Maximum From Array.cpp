//Leetcode Link : https://leetcode.com/problems/removing-minimum-and-maximum-from-array

//Approach (simple obervation - 3 options only)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElIdx = min_element(begin(nums), end(nums)) - begin(nums);
        int maxElidx = max_element(begin(nums), end(nums)) - begin(nums);

        int left  = min(minElIdx, maxElidx);
        int right = max(minElIdx, maxElidx);

        return min({left+1+n-right, right+1, n-left});
    }
};
