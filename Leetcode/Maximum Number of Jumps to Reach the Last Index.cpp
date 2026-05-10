//Leetcode Link : https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index

//Approach-1 (Recursion + Memo)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int n;

    int solve(int i, vector<int>& nums, int target, vector<int>& t) {
        if(i == n-1) {
            return t[i] = 0; //no more steps. reached destination
        }

        if(t[i] != INT_MIN) {
            return t[i];
        }

        int result = INT_MIN;

        for(int j = i+1; j < n; j++) {
            if(abs(nums[i] - nums[j]) <= target) {
                int temp = 1 + solve(j, nums, target, t);

                result = max(result, temp);
            }
        }

        return t[i] = result;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        vector<int> t(n+1, INT_MIN);

        int result = solve(0, nums, target, t);

        
        return result < 0 ? -1 : result;

    }
};



//Approach-2 (Bottom Up)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> t(n+1, INT_MIN);

        t[n-1] = 0;

        for(int i = n-2; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target &&
                    t[j] != INT_MIN) {
                        int temp = 1 + t[j];

                        t[i] = max(t[i], temp);
                    }
            }
        }

        return t[0] < 0 ? -1 : t[0];

        
    }
};
