//Approach:
/*
I solved this problem using dynamic programming. 
Here's the intuition behind it:
  • To Calculating the number of unique subsequences 
    for the 'ith' character is double the number of subsequences 
    for the 'i-1th' character.
  • However, there's a catch. We need unique subsequences, 
    so we check the last occurrence of the current character 
    and subtract it from the total number of subsequences to get our final answer.

Here's how it works:
Create a vector last of size 26, initialized with -1. This vector will store the last occurrence of each character in the string s.
Create a dynamic programming array dp of size n+1, where n is the length of the input string s. Initialize dp[0] to 1 because there is one empty subsequence.
Loop through the characters of the string s from left to right (index i from 1 to n).
{ Calculate dp[i] as dp[i-1]*2, which represents the total number of subsequences that include the current character s[i-1].
  Find the last occurrence of the current character s[i-1] using the last vector.
  If lastOccur is not -1 (i.e., the character has occurred before), subtract dp[lastOccur] from dp[i]. This step removes the count of subsequences that include duplicate characters, ensuring distinct subsequences.
  Perform modulo mod to keep the values  dp[i] within a valid range.
  Update the last vector with the current index i-1 for the character s[i-1]. }
Return dp[n], which represents the total number of distinct subsequences of the input string s.
*/
class Solution {
  public:
    static const int MOD = 1000000007;
    
    int distinctSubseq(string &str) {
        // code here
        int n = str.length();
        vector<long long> dp(n + 1);
        dp[0] = 1; 

        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {
            int ch = str[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1]) % MOD;

            if (last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]] + MOD) % MOD;
            }

            last[ch] = i - 1;
        }

        return dp[n];
    }
};
