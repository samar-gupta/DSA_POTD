/*
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/sort-array-by-parity/
*/

/************************************************************ C++ ************************************************************/


// Approach-1 (Using simple iteration)
// T.C : O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        
        for(int i = 0; i<nums.size(); i++) {
            
            if(nums[i]%2 == 0) {//even
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        return nums;
    }
};