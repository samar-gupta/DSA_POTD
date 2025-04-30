//Leetcode Link : https://leetcode.com/classic/problems/find-numbers-with-even-number-of-digits/description/

class Solution {
public:
    int findNumbers(vector<int>& nums) {     
        int evenDigitCount = 0;

        for (int num : nums) {
            int digitCount = floor(log10(num)) + 1;
            if (digitCount % 2 == 0)
                evenDigitCount++;
        }

        return evenDigitCount;
    }
};
