class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();

        vector<int> bestEndingHere(n);

        bestEndingHere[0] = arr[0];

        for (int i = 1; i < n; i++) {
            bestEndingHere[i] = max(arr[i], bestEndingHere[i - 1] + arr[i]);
        }

        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int ans = windowSum;

        for (int i = k; i < n; i++) {

            windowSum -= arr[i - k];

            windowSum += arr[i];

            ans = max(ans, windowSum);

            ans = max(ans, windowSum + bestEndingHere[i - k]);
        }

        return ans;
    }
};
