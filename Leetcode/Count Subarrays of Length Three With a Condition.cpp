//Leetcode Link : https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/

//Approach (Striaght forward simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i = 1; i < n-1; i++) {
            if(nums[i] == (nums[i-1] + nums[i+1])*2) {
                result++;
            }
        }

        return result;
    }
};
