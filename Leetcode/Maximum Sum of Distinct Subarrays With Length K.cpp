//Leetcode Link : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

//Approach (Using classic sliding window template + using set/map to keep distinct element)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        long long result = 0;
        long long currWindowSum = 0;
        unordered_set<int> st;

        while (j < nums.size()) {
            // Adjust the window if nums[j] is already in the set
            while (st.count(nums[j])) {
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWindowSum += nums[j];
            st.insert(nums[j]);

            // Check if the window size is equal to k
            if (j - i + 1 == k) {
                result = max(result, currWindowSum);

                // Shrink the window from the left
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return result;
    }
};
