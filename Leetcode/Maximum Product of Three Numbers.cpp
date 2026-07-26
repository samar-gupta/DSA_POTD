//Leetcode Link : https://leetcode.com/problems/maximum-product-of-three-numbers/description/

//Approach-1 : 
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int &num : nums) {
            if(num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if(num > max2) {
                max3 = max2;
                max2 = num;
            } else if(num > max3) {
                max3 = num;
            }

            //We can have negative numbers as well
            //{1, 2, 3, -4, -5}
            //here best answer is not 1*2*3 = 6
            //Best answer is 3*-4*-5 = 60 (two negatives made positive)

            if(num < min1) {
                min2 = min1;
                min1 = num;
            } else if(num < min2) {
                min2 = num;
            }
        }

        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
