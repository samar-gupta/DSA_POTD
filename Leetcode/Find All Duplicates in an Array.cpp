//Company Tags   : Pocket Gems, Amazon, Meta
//Leetcode Link  : https://leetcode.com/problems/find-all-duplicates-in-an-array

//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result; 
        for(int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            int idx = num - 1;
            
            if(nums[idx] < 0) {
                result.push_back(num);
            } else {
                nums[idx] *= -1;
            }
        }
        
        return result;
        
    }
};
