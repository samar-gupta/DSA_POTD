//Leetcode Link : https://leetcode.com/problems/sum-of-squares-of-special-elements/description/

//Approach -1 (Simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (n % (i + 1) == 0) {
                result += (nums[i] * nums[i]);
            }
        }
        return result;
    }
};


//Approach -2 (We only care about divisors of n)
//T.C : O(sqrt(n))
//S.C : O(1)
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                //i is a factor of n, so nums[i-1]*nums[i-1]
                result += nums[i - 1] * nums[i - 1];

                if (i * i != n) { //if not perfect square
                    //n/i is the other factor, so nums[n/i-1]*nums[n/i-1]
                    result += nums[n / i - 1] * nums[n / i - 1];
                }
            }
        }
        return result;
    }
};
