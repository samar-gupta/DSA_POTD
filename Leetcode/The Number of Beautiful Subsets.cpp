//Leetcode Link : https://leetcode.com/problems/the-number-of-beautiful-subsets/

//Simple backtracking just like subsets
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:

    int result;
    int K;
    void dfs(vector<int> &nums, int idx, unordered_map<int, int> &mp) {

        if(idx == nums.size()) {
            result++;
            return;
        }

        //not_take
        dfs(nums, idx+1, mp);
        
        //checking if we can take it or not
        if(!mp[nums[idx] - K] && !mp[nums[idx] + K]) {
                mp[nums[idx]]++;
                dfs(nums, idx + 1, mp);
                mp[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        result = 0;
        K = k;

        unordered_map<int, int> mp;
 
        dfs(nums, 0, mp);

        return result - 1; //-1 because we don't want to count empty subset in result
    }
};
