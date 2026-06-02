class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());

        int ans = 0;
        int n = arr.size();

        int i = n - 1;

        while (i > 0) {

            if (arr[i] - arr[i - 1] < k) {

                ans += arr[i] + arr[i - 1];

                i -= 2;
            }
            else {

                i--;
            }
        }

        return ans;
    }
};
