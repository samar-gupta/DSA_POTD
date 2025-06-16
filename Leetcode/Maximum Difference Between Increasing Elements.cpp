//Leetcode Link : https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/

//Approach (Simple iteration)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElementi = nums[0];
        int maxDiff = -1;

        for(int j = 1; j < n; j++) {
            if(nums[j] > minElementi) {
                maxDiff = max(maxDiff, nums[j] - minElementi);
            } else {
                minElementi = nums[j];
            }
        }

        return maxDiff;
    }
};
