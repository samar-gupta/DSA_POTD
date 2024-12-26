//Leetcode Link : https://leetcode.com/problems/target-sum/

//Approach-1 (Normal Recursion & Memoization using unordered_map)
//T.C : O(n*totalSum)
//S.C : O(n*totalSum)
class Solution {
public:
    int solve(vector<int>& nums, int &target, int i, int sum, unordered_map<string, int>& memo) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        // Create a unique key for the current state
        string key = to_string(i) + "," + to_string(sum);

        // Check if the result is already computed
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Compute the result recursively
        int plus = solve(nums, target, i + 1, sum + nums[i], memo);
        int minus = solve(nums, target, i + 1, sum - nums[i], memo);

        // Store the result in the memo
        memo[key] = plus + minus;

        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return solve(nums, target, 0, 0, memo);
    }
};


//Approach-2 (Normal Recursion & Memoization using vector)
//T.C : O(n*totalSum)
//S.C : O(n*totalSum)
class Solution {
public:
    int S;
    int solve(vector<int>& nums, int &target, int i, int sum, vector<vector<int>>& t) {
        if(i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        if(t[i][sum+S] != INT_MIN) {
            return t[i][sum+S];
        }
        int plus  = solve(nums, target, i+1, sum+nums[i], t);
        int minus = solve(nums, target, i+1, sum-nums[i], t);

        return t[i][sum+S] = plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        S = accumulate(begin(nums), end(nums), 0);
        vector<vector<int>> t(n, vector<int>(2*S+1, INT_MIN));
        return solve(nums, target, 0, 0, t);
    }
};
