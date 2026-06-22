class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int left = 0, right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int width = right - left - 1;
            ans = max(ans, min(height[left], height[right]) * width);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};
