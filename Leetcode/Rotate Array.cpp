//Leetcode Link         : https://leetcode.com/problems/rotate-array/description/
//Next Leetcode Qn Link : https://leetcode.com/problems/shift-2d-grid/description/

//Approach (Reverse Trick)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;
        if (k == 0) 
            return;

        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        };

        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }
};
