//Leetcode Link : https://leetcode.com/problems/maximum-product-of-two-digits/description/

//Approach-1 :
class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;

        while (n > 0) {
            int x = n % 10;
            digits.push_back(x);
            n /= 10;
        }

        sort(begin(digits), end(digits), greater<int>());

        return digits[0] * digits[1];
    }
};



//Approach-2 : 
class Solution {
public:
    int maxProduct(int n) {
        int maxDigit = 0;
        int secondMaxDigit = 0;
        
        while(n > 0) {
            int r = n%10;
            if(maxDigit < r) {
                secondMaxDigit = maxDigit;
                maxDigit = r; 
            } else if(secondMaxDigit < r) {
                secondMaxDigit = r;
            } 
            n /= 10;
        }
        
        return maxDigit * secondMaxDigit;
    }
};



class Solution {
public:
    int maxProduct(int n) {
        int maxDigit = 0;
        int secondMaxDigit = 0;

        while (n > 0) {
            int d = n % 10;

            if (d > maxDigit) {
                secondMaxDigit = maxDigit;
                maxDigit = d;
            } else if (d > secondMaxDigit) {
                secondMaxDigit = d;
            }

            n /= 10;
        }

        return maxDigit * secondMaxDigit;
    }
};
