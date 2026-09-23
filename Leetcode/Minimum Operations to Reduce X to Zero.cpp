//Company Tags  : AMAZON
//Leetcode Link : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

//Using longest subarray Sum logic
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {        
        int n    = nums.size();
        int sum  = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x)
            return -1;
        int restSum  = sum-x;
        int longest  = INT_MIN;
        sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(mp.count(sum-restSum)) {
                longest = max(longest, i-mp[sum-restSum]);
            }
        }
        
        return longest==INT_MIN?-1:n-longest;
    }
};

//Approach-2 (Using Recursion) - You Can memoize it as well but it will still give TLE
//T.C : O(2^n) -  We take and skip each ith and jth index
//S.C : O(1) excluding Stack space
class Solution {
    int minCount;
public:
    void solve(vector<int>& nums, int remain, int count, int i, int j) {
        if (remain == 0) {
            minCount = min(minCount, count);
            return;
        }
        else if (remain < 0 || i > j || count >= minCount)
            return;
        else {
            solve(nums, remain - nums[i], count + 1, i + 1, j);
            solve(nums, remain - nums[j], count + 1, i, j - 1);
        }
    }
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        minCount = INT_MAX;

        solve(nums, x, 0, 0, n-1);
        
        if (minCount == INT_MAX) 
            return -1;
        
        return minCount;
    }
};
