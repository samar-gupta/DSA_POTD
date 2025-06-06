//Leetcode Link : https://leetcode.com/problems/maximum-ascending-subarray-sum

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;

        for(int i = 0; i < n; i++) {

            int sum = nums[i];
            int j = i+1;
            while(j < n && nums[j] > nums[j-1]) {
                sum += nums[j];
                j++;
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};



//Approach-2 (Optimal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;
        int sum = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                sum += nums[i];
            } else {
                maxSum = max(maxSum, sum); //60
                sum = nums[i]; //5
            }
        }

        return max(maxSum, sum);
    }
};
