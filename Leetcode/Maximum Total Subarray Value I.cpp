//Leetcode Link : https://leetcode.com/problems/maximum-total-subarray-value-i/

//Approach (Linear Scan - find max and min)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxEl = INT_MIN;
        int minEl = INT_MAX;

        for(int &num : nums) {
            maxEl = max(maxEl, num);
            minEl = min(minEl, num);
        }

        return 1LL*(maxEl - minEl)*k;
    }
};
