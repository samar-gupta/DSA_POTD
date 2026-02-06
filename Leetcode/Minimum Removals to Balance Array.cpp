//Leetcode Link : https://leetcode.com/problems/minimum-removals-to-balance-array

//Approach (Using sorting and two pointers)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int maxEl = nums[0];
        int minEl = nums[0];

        int L = 1;
        int i = 0;
        int j = 0;

        while(j < n) {
            maxEl = nums[j];
            minEl = nums[i];

            while(i < j && maxEl > (long long)k * minEl) {
                i++;
                minEl = nums[i];
            }

            L = max(L, j-i+1);
            j++;
        }

        return n - L;
    }
};
