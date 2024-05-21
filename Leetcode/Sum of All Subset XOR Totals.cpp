//Company Tags  : Google, Meta
//Leetcode Link : https://leetcode.com/problems/sum-of-all-subset-xor-totals

//Approach-1 (Using simple backtracking to generate subsets)
//T.C : O(n * 2^n)
//S.C : O(n * 2^n)
class Solution {
public:

    void solve(vector<int>& nums, int i, vector<int>& currSubset,
                         vector<vector<int>>& subsets) {

        if (i == nums.size()) {
            subsets.push_back(currSubset);
            return;
        }

        currSubset.push_back(nums[i]);
        solve(nums, i + 1, currSubset, subsets);
        currSubset.pop_back();
        solve(nums, i + 1, currSubset, subsets);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;
        solve(nums, 0, currSubset, subsets);

        int result = 0;
        for (auto& currSubset : subsets) {
            int Xor = 0;
            for (int num : currSubset) {
                Xor ^= num;
            }
            result += Xor;
        }
        return result;
    }
};



//Approach-2 (Using optimal backtracking)
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:

    int solve(int i, vector<int>& nums, int Xor) {
        if(i == nums.size()) {
            return Xor;
        }

        int include = solve(i+1, nums, nums[i] ^ Xor);
        int exclude = solve(i+1, nums, Xor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
    }
};



//Approach-3 (Observing pattern)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int &num : nums) {
            result |= num;
        }

        return result << (n-1);
    }
};
