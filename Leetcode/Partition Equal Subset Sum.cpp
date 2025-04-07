//Company tags  : Accolite, Amazon, Adobe, Drishti-Soft
//Leetcode Link : https://leetcode.com/problems/partition-equal-subset-sum/

//Approach-1 (Recursion + Memo)
//T.C : O(n*x), where x = totalSum/2
//S.C : O(n*x)
class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums, int i, int x) {
        if(x == 0) {
            return true;
        }

        if(i >= nums.size()) {
            return false;
        }

        if(t[i][x] != -1) {
            return t[i][x];
        }

        bool take = false;
        if(nums[i] <= x) {
            take = solve(nums, i+1, x - nums[i]);
        }

        bool not_take = solve(nums, i+1, x);

        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int S = accumulate(begin(nums), end(nums), 0);

        if(S%2 != 0) {
            return false;
        }  
        memset(t, -1, sizeof(t));
        //vector<vecyot<int>> t(n+1, vector<int>(x+1, -1))
        int x = S/2;

        return solve(nums, 0, x);

    }
};
