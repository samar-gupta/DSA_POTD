//Leetcode Link : https://leetcode.com/problems/minimum-distance-to-the-target-element

//Approach-1 (Simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int result = INT_MAX;

        //result = x;
        //abs(start - i) minimal

        for(int i = 0; i < n; i++) {

            if(nums[i] == target) {
                result = min(result, abs(i - start));
            }

        }

        return result;
    }
};



//Approach-2 (Loop with Early Break)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int result = INT_MAX;

        //result = x;
        //abs(start - i) minimal

        for(int i = 0; i < n && result > abs(i - start); i++) {

            if(nums[i] == target) {
                result = min(result, abs(i - start));
            }

        }

        return result;
    }
};
