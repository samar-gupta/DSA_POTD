//Leetcode Link : https://leetcode.com/problems/left-and-right-sum-differences/description/

//Approach-1 : 
//T.C : O(n)
//S.C : O(1) //better from O(n) ~ taking 2 vec for leftsum & rightsum
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
               
        int sum = accumulate(begin(nums), end(nums), 0);
        
        vector<int> result(n);
        int curr = 0;
        
        for(int i = 0; i < n; i++) {
            
            int leftSum = curr;
            
            curr += nums[i];
            
            int rightSum = sum - curr;
            
            result[i] = abs(rightSum - leftSum);
        }
        
        return result;
    }
};
