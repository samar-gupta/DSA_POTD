class Solution {
  public:
    bool canSplit(vector<int>& nums, int &maxSum, int &k) {
        int chunks = 1, currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                chunks++;
                currentSum = num;
                if (chunks > k) return false; // More chunks than allowed
            } else {
                currentSum += num;
            }
        }
        return true;
    }
    
    int minTime(vector<int>& nums, int k) {
        // code here
        int low = 0, high = 0;

        // Initialize low as max(nums) and high as sum(nums)
        for (int num : nums) {
            low = max(low, num);
            high += num;
        }

        int ans = high; // Store the minimum max sum

        // Binary search to find the optimal max sum
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, mid, k)) {
                ans = mid; // Update answer
                high = mid - 1; // Try for a smaller max sum
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
