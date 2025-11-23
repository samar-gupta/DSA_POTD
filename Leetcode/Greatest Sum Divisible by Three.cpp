//Leetcode Link : https://leetcode.com/problems/greatest-sum-divisible-by-three

//Approach-1 - Greedily using %3 property
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> remain1, remain2;

        for (int num : nums) {
            sum += num;
            
            if (num % 3 == 1)
                remain1.push_back(num);
            else if (num % 3 == 2) 
                remain2.push_back(num);
        }

        if (sum % 3 == 0) 
            return sum;

        sort(begin(remain1), end(remain1));
        sort(begin(remain2), end(remain2));

        int result = 0;
        //anything % 3 can only be 0 or 1 or 2

        if (sum % 3 == 1) {
            int remove1 = remain1.size() >= 1 ? remain1[0] : INT_MAX;
            int remove2 = remain2.size() >= 2 ? remain2[0] + remain2[1] : INT_MAX;
            result      = sum - min(remove1, remove2);
        } 
        else { // sum % 3 == 2
            int remove1 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
            int remove2 = remain1.size() >= 2 ? remain1[0] + remain1[1] : INT_MAX;
            result      = sum - min(remove1, remove2);
        }

        return result < 0 ? 0 : result;
    }
};


//Approach-2 - Recursion Memoization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int solve(int i, int remainder, vector<int>& nums, vector<vector<int>>& t) {
        if (i >= nums.size()) {
            return (remainder == 0) ? 0 : INT_MIN;
        }

        if (t[i][remainder] != -1)
            return t[i][remainder];

        // Pick the current number
        int pick = nums[i] +
                   solve(i + 1, (remainder + nums[i]) % 3, nums, t);

        // Skip the current number
        int notPick = solve(i + 1, remainder, nums, t);

        return t[i][remainder] = max(pick, notPick);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int>(3, -1));
        return solve(0, 0, nums, t);
    }
};


//Approach-3 - Bottom up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(3, INT_MIN));

        // Base case: i == n
        t[n][0] = 0;       // valid
        t[n][1] = INT_MIN; // invalid
        t[n][2] = INT_MIN; // invalid

        // Fill DP from bottom to top
        for (int i = n - 1; i >= 0; --i) {
            for (int rem = 0; rem < 3; rem++) {

                // Option 1: pick nums[i]
                int newRem = (rem + nums[i]) % 3;
                int pick = (t[i + 1][newRem] == INT_MIN) 
                           ? INT_MIN 
                           : nums[i] + t[i + 1][newRem];

                // Option 2: skip nums[i]
                int notPick = t[i + 1][rem];

                // maximize
                t[i][rem] = max(pick, notPick);
            }
        }

        return t[0][0];
    }
};
