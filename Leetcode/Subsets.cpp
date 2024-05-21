//Company Tags   : Microsoft
//Leetcode Link  : https://leetcode.com/problems/subsets/

//Approach - (Recursion with Backtracking)
//T.C : O(2^n)
//S.C : O(2^n*length of each subset) to store each subset
//The recursion stack space complexity is O(N) , the maximum depth of the recursion is N, where N is the length of the input array.
class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int idx, vector<int>& temp) {
        if(idx >= nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, idx+1, temp);
        temp.pop_back();
        solve(nums, idx+1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        solve(nums, 0, temp);

        return result;
    }
};
