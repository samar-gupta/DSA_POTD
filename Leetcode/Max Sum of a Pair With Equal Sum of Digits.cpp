//Leetcode Link : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

//Approach-1 (Brute Force)
//T.C : O(n^2 * m), m = number of digits
//S.C : O(1)
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        for(int i = 0; i < n; i++) {
            int digitSumi = getDigitSum(nums[i]);

            for(int j = i+1; j < n; j++) {
                int digitSumj = getDigitSum(nums[j]);

                if(digitSumi == digitSumj) {
                    result = max(result, nums[i] + nums[j]);
                }
            }
        }

        return result;
    }
};


//Approach-2 (Optimal using Map)
//T.C : O(n*m), m = number of digits
//S.C : O(n)
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int digitSum = getDigitSum(nums[i]);

            if(mp.count(digitSum)) {
                result = max(result, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }

        return result;
    }
};


//Approach-2 (Optimal array as Map of constant size)
//T.C : O(n*m), m = number of digits
//S.C : O(1)
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);

            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int result = -1;

        int mp[82] = {0};

        for(int i = 0; i < n; i++) {
            int digitSum = getDigitSum(nums[i]);

            if(mp[digitSum] > 0) {
                result = max(result, nums[i] + mp[digitSum]);
            }

            mp[digitSum] = max(mp[digitSum], nums[i]);
        }

        return result;
    }
};
