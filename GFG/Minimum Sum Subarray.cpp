class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int curr = arr[0];
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = min(arr[i], curr + arr[i]);
            ans = min(ans, curr);
        }
        return ans;
    }
};
