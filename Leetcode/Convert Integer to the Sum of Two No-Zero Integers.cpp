//Leetcode Link : https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers

//Approach-1 (Brute Force - Try all possible numbers fro 1 to n-1 for a and thne b = n-a)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:

    bool check(int num) {
        while(num) {
            if(num%10 == 0) {
                return false;
            }

            num /= 10;
        }   

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a <= n-1; a++) {
            int b = n-a;

            if(check(a) && check(b)) {
                return {a, b};
            }
        }

        return {};
    }
};


//Approach-2 (Fixing each digit and forming a and b digit by digit)
//T.C : O(logn)
//S.C : O(1)
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int placeValue = 1;

        //a+b == n
        while(n > 1) {
            int take = 1;

            if(n%10 == 1) {
                take = 2;
            }

            a = a - take*placeValue;
            b = b + take*placeValue;

            n = (n-take)/10; //moving to next digit

            placeValue *= 10;
        }

        return {a, b};
    }
};
