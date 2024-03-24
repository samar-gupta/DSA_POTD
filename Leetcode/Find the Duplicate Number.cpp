//Company Tags   : AMAZON
//Leetcode Link  : https://leetcode.com/problems/find-the-duplicate-number/

//NOTE : We can solve this using O(n) space, or in O(n^2) Time Complexity using double for loop to find the duplicate number

//T.C : O(n) Using "Hare & tortoise technique"
//S.C : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
