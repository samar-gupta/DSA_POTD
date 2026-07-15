//Leetcode Link : https://leetcode.com/problems/gcd-of-odd-and-even-sums

//Approach-1 (Simple Maths)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // Sum of first n odd numbers  = n * n
        // Sum of first n even numbers = n * (n + 1)
        return __gcd(n * n, n * (n + 1)); 
    }
};


//Approach-2 (Simple Maths and Constant Time)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // gcd(n*n, n*(n+1)) = n * gcd(n, n+1) = n * 1 = n
        return n;
    }
};
