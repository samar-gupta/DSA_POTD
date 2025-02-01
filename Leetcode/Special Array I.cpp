//Leetcode Link : https://leetcode.com/problems/special-array-i

//Approach-1 (Simple iteration)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <= n-2; i++) {
            if(nums[i]%2 == nums[i+1]%2) {
                return false;
            }
        }

        return true;
    }
};


//Approach-2 (Using Bit magic)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <= n-2; i++) {
            if((nums[i]&1) == (nums[i+1]&1)) {
                return false;
            }
        }
        return true;
    }
};
