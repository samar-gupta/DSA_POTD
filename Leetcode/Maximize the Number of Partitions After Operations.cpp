//Leetcode Link : https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/

//Approach : Usin Recursion + Memo with Bit Memoization (Digit DP)
//T.C : Without memoization - )(2^n * 26) , With Memoization - O(n*uniqueChars)
//S.C : O(m+n) - where m = unique states (resursion stack) and n = size of map
class Solution {
public:
    unordered_map<long long, int> mp;
    string S;
    int K;
        
    int solve(long long i, long long uniqueChars, bool canChange) {
        long long key = (i << 27) | (uniqueChars << 1) | (canChange);
        /*
        i << 27: Left-shifting i by 27 bits. This is done to occupy the most significant bits with the value of i.
        uniqueChars << 1: Left-shifting uniqueChars by 1 bit. 
                          This is done to make space for the least significant bit, 
                          which will be used to represent the boolean value of canChange.
        canChange: This boolean value is ORed with the result of the left-shift operations.
        */

        if (mp.count(key)) {  // Replaced cache with mp
            return mp[key];
        }

        if (i == S.size()) {
            return 0;
        }

        int characterIndex = S[i] - 'a';
        int uniqueCharsUpdated = uniqueChars | (1 << characterIndex);
        int uniqueCharCount = __builtin_popcount(uniqueCharsUpdated);

        int result;
        if (uniqueCharCount > K) {
            result = 1 + solve(i + 1, 1 << characterIndex, canChange);
        } else {
            result = solve(i + 1, uniqueCharsUpdated, canChange);
        }

        if (canChange) {
            for (int newCharIndex = 0; newCharIndex < 26; ++newCharIndex) {
                int newSet = uniqueChars | (1 << newCharIndex);
                int newUniqueCharCount = __builtin_popcount(newSet);

                if (newUniqueCharCount > K) {
                    result = max(result, 1 + solve(i + 1, 1 << newCharIndex, false));
                } else {
                    result = max(result, solve(i + 1, newSet, false));
                }
            }
        }

        return mp[key] = result;
    }
    
    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;
        return solve(0, 0, true) + 1;
    }
};
