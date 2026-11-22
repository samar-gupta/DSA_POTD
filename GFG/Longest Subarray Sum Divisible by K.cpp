/*
Approach:
  1. Keep a running prefix sum and calculate its remainder when divided by k.
  2. Store the first index where each remainder appears. Initialize remainder 0 with index -1.
  3. If the same remainder appears again, the subarray between those two indices has a sum divisible by k.
  4. Update the maximum length using the current index and the first index of that remainder.
  5. If the remainder is new, store its index. Keep the first occurrence to get the longest possible subarray.
  At the end, return the maximum length.
*/

class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> first;
        long long sum = 0;
        int maxLen = 0;
        first[0] = -1;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            int rem = ((sum % k) + k) % k;
            if (first.count(rem)) {
                maxLen = max(maxLen, i - first[rem]);
            } else {
                first[rem] = i;
            }
        }
        return maxLen;
    }
};
