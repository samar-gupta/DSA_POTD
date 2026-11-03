//Leetcode Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/

//T.C: O(n)
//S.C: O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));
        
        int moves = 0;      
        for (int& num : nums) {
            moves += maxEl - num;
        }
        /*      
          Or you can do it like this:
          moves = (maxEl - nums[0]) + (maxEl - nums[1]) + .....
          moves = (maxEl + maxEl + ...) - (nums[0] + nums[1]
        
          Final moves = n*maxEl - sum(nums);
        */
        
        return moves;
    }
};
