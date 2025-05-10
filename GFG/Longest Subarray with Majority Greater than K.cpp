class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        vector<int> transformed(n);

        for(int i = 0; i < n; ++i) {
            transformed[i] = (arr[i] > k) ? 1 : -1;
        }

        unordered_map<int, int> firstIndex;
        int prefixSum = 0;
        int maxLength = 0;

        for(int i = 0; i < n; ++i) {
            prefixSum += transformed[i];

            if (prefixSum > 0) {
                maxLength = i + 1;
            } else {
                if(firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                    maxLength = max(maxLength, i - firstIndex[prefixSum - 1]);
                }
            }

            if(firstIndex.find(prefixSum) == firstIndex.end()) {
                firstIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};
