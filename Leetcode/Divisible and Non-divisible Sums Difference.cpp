//Leetcode Link : https://leetcode.com/problems/divisible-and-non-divisible-sums-difference

//Brute Force - T.C : O(n)

//Approach - Constant time using maths
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n/m;                           //k = number of divisible terms, k = floor of (n/m) or simple integer division 

        return n*(n+1)/2 - m * k * (k+1);      //ans=num1-num2, num1 = total_sum - num2, num2 = m* k*(k+1)/2
    }
};
