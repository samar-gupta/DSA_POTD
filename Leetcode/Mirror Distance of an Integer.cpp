//Leetcode Link : https://leetcode.com/problems/mirror-distance-of-an-integer/description/

//Approach-1 (Simple reverse and find)
//T.C : O(log(n)), for reversing
//S.C : O(1)
class Solution {
public:
    int getReverse(int n) {
        int result = 0;

        while (n) {
            int rem = n%10;
            result  = (result * 10) + rem;
            n      /= 10;
        }

        return result;
    }

    int mirrorDistance(int n) {
        return abs(n - getReverse(n));
    }
};



//Approach-2 (Simple reverse and find)
//T.C : O(log(n)), for reversing
//S.C : O(log(n)) storing string version of n
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));
        
        int rev = stoi(s);
        return abs(n - rev);
    }
};
