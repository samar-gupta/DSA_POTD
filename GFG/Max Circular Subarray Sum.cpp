//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size();

        // Variables to track sums
        int totalSum = 0;        // Total sum of the array
        int maxEnding = 0;       // Maximum sum ending at the current index
        int minEnding = 0;       // Minimum sum ending at the current index
        int ansMax = INT_MIN;    // Maximum subarray sum for non-circular case
        int ansMin = INT_MAX;   // Minimum subarray sum

        for (int i = 0; i < n; ++i) {
            // Update Kadane's max sum ending at current index
            maxEnding = max(maxEnding + arr[i], arr[i]);
            ansMax = max(ansMax, maxEnding);

            // Update Kadane's min sum ending at current index
            minEnding = min(minEnding + arr[i], arr[i]);
            ansMin = min(ansMin, minEnding);

            // Update the total sum of the array
            totalSum += arr[i];
        }

        if(ansMax < 0) return ansMax; //if maximum subarray sum is -ve, means all items are -ve. Hence return max subarray sum
        // Return the maximum of non-circular and circular cases
        return max(ansMax, totalSum - ansMin);
    }
};
