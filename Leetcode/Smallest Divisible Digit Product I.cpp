//Leetcode Link : https://leetcode.com/problems/smallest-divisible-digit-product-i/

//Approach : 
class Solution {
public:
    int findDigitsProd(int num) {
        int prod = 1;
        //num = 12304567
        //prod = 7 * 6 * 5 * 4 * 0
        while(num) { //log10(num)
            prod = prod * (num%10);

            if(prod == 0) //early return
                return 0;

            num /= 10;
        }

        return prod;
    }

    int smallestNumber(int n, int t) {
        //T.C : O(10 * log10(num)) = O(log(num))
        for(int num = n; num <= n+10; num++) { //O(10)
            if(findDigitsProd(num) % t == 0) {
                return num;
            }
        }

        return -1;
    }
};
