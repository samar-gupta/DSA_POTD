//Leetcode Link : https://leetcode.com/problems/number-of-substrings-with-only-1s

//Approach-1 (Simple maths formula to count substrings)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    const int M = 1e9+7;

    int numSub(string s) {
        long long result = 0;
        long long count1 = 0;

        for(char ch : s) {
            if (ch == '1') {
                count1++;
            } else {
                result = (result + count1 * (count1 + 1) / 2) % M;
                count1 = 0;
            }
        }

        // Adding the last group of 1s
        result = (result + count1 * (count1 + 1) / 2) % M;

        return (int)result;
    }
};


//Approach-2 (Simple maths formula to count substrings)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    const int M = 1e9+7;

    int numSub(string s) {
        int result = 0;
        int count1 = 0;

        for(char ch : s) {
            if (ch == '1') {
                count1++;
                result = (result + count1) % M;
            } else {
                count1 = 0;
            }
        }

        return result;
    }
};
