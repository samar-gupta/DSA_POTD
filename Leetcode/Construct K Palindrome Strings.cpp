//Leetcode Link : https://leetcode.com/problems/construct-k-palindrome-strings

//Approach - (Using the fact that odd frequency characters count control the palindromes count)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(n < k) {
            return false;
        }

        if(n == k) {
            return true;
        }

        vector<int> vec(26, 0);
        for(char &ch : s) {
            vec[ch-'a']++;
        }

        int oddFreqCharCount = 0;
        for(int i = 0; i < 26; i++) {
            if(vec[i]%2 != 0) {
                oddFreqCharCount++;
            }
        }

        return oddFreqCharCount <= k;
    }
};
